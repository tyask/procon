from typing import Dict, Any, Optional

import os
from atcodertools.codegen.code_style_config import CodeStyleConfig
from atcodertools.codegen.models.code_gen_args import CodeGenArgs
from atcodertools.codegen.template_engine import render
from atcodertools.fmtprediction.models.format import Pattern, SingularPattern, ParallelPattern, TwoDimensionalPattern, \
    Format
from atcodertools.fmtprediction.models.type import Type
from atcodertools.fmtprediction.models.variable import Variable


def _loop_header(var: Variable, for_second_index: bool):
    if for_second_index:
        index = var.second_index
        loop_var = "j"
    else:
        index = var.first_index
        loop_var = "i"

    return "rep({loop_var},{length})".format(
        loop_var=loop_var,
        length=index.get_length()
    )


class CppCodeGenerator:

    def __init__(self,
                 format_: Optional[Format[Variable]],
                 config: CodeStyleConfig):
        self._format = format_
        self._config = config

    def generate_parameters(self) -> Dict[str, Any]:
        if self._format is None:
            return dict(prediction_success=False)

        return dict(formal_arguments=self._formal_arguments(),
                    actual_arguments=self._actual_arguments(),
                    input_part=self._input_part(),
                    prediction_success=self._enable_prediction())

    def _enable_prediction(self):
        return os.getenv('ENABLE_PREDICTION')

    def _input_part(self):
        lines = []
        for pattern in self._format.sequence:
            lines += self._render_pattern(pattern)
        return "\n{indent}".format(indent=self._indent(1)).join(lines)

    def _convert_type(self, type_: Type) -> str:
        if type_ == Type.float:
            return "ld"
        elif type_ == Type.int:
            return "ll"
        elif type_ == Type.str:
            return "str"
        else:
            raise NotImplementedError

    def _get_declaration_type(self, var: Variable):
        ctype = self._convert_type(var.type)
        for _ in range(var.dim_num()):
            ctype = 'vec<{}>'.format(ctype)
        return ctype

    def _actual_arguments(self) -> str:
        """
            :return the string form of actual arguments e.g. "N, K, a"
        """
        return ", ".join([
            v.name if v.dim_num() == 0 else 'move({})'.format(v.name)
            for v in self._format.all_vars()])

    def _formal_arguments(self):
        """
            :return the string form of formal arguments e.g. "int N, int K, std::vector<int> a"
        """
        return ", ".join([
            "{decl_type} {name}".format(
                decl_type=self._get_declaration_type(v),
                name=v.name)
            for v in self._format.all_vars()
        ])

    def _generate_declaration(self, var: Variable):
        """
        :return: Create declaration part E.g. array[1..n] -> std::vector<int> array = std::vector<int>(n-1+1);
        """
        if var.dim_num() == 0:
            return None
        elif var.dim_num() == 1:
            dims = [var.first_index.get_length()]
        elif var.dim_num() == 2:
            dims = [var.first_index.get_length(),
                    var.second_index.get_length()]
        else:
            raise NotImplementedError

        if len(dims) == 0:
            ctor = ''
        elif len(dims) == 1:
            ctor = '({})'.format(dims[0])
        else:
            ctor = '({})'.format(dims[-1])
            ctype = self._convert_type(var.type)
            for dim in dims[-2::-1]:
                ctype = 'vec<{}>'.format(ctype)
                ctor = '({},{}{})'.format(dim, ctype, ctor)

        line = "{decl_type} {name}{constructor};".format(
            name=var.name,
            decl_type=self._get_declaration_type(var),
            constructor=ctor
        )
        return line

    def _input_code_for_var(self, var: Variable) -> str:
        name = self._get_var_name(var)
        if var.type == Type.float:
            return 'DBL({name});'.format(name=name)
        elif var.type == Type.int:
            return 'LL({name});'.format(name=name)
        elif var.type == Type.str:
            return 'STR({name});'.format(name=name)
        else:
            raise NotImplementedError

    def _input_code_for_declared_var(self, var: Variable) -> str:
        name = self._get_var_name(var)
        return 'input({name});'.format(name=name)

    @staticmethod
    def _get_var_name(var: Variable):
        name = var.name
        if var.dim_num() >= 1:
            name += "[i]"
        if var.dim_num() >= 2:
            name += "[j]"
        return name

    def _render_pattern(self, pattern: Pattern):
        lines = []
        for var in pattern.all_vars():
            decl = self._generate_declaration(var)
            if decl:
                lines.append(decl)

        representative_var = pattern.all_vars()[0]
        if isinstance(pattern, SingularPattern):
            lines.append(self._input_code_for_var(representative_var))
        elif isinstance(pattern, ParallelPattern):
            line = _loop_header(representative_var, False) + ' { '
            for var in pattern.all_vars():
                line += '{input} '.format(input=self._input_code_for_declared_var(var))
            line += '}'
            lines.append(line)
        elif isinstance(pattern, TwoDimensionalPattern):
            line = _loop_header(representative_var, False) + ' '
            line += _loop_header(representative_var, True) + ' { '
            for var in pattern.all_vars():
                line += '{input} '.format(input=self._input_code_for_declared_var(var))
            line += '}'
            lines.append(line)
        else:
            raise NotImplementedError

        return lines

    def _indent(self, depth):
        return self._config.indent(depth)


class NoPredictionResultGiven(Exception):
    pass


def main(args: CodeGenArgs) -> str:
    code_parameters = CppCodeGenerator(
        args.format, args.config).generate_parameters()
    return render(
        args.template,
        mod=args.constants.mod,
        yes_str=args.constants.yes_str,
        no_str=args.constants.no_str,
        **code_parameters
    )
