#! /usr/bin/env python

import os
import sys
from jinja2 import Template, Environment, FileSystemLoader


template_file = sys.argv[1]
dir = os.path.dirname(template_file)
file = os.path.basename(template_file)

env = Environment(loader=FileSystemLoader(dir))
template = env.get_template(file)

data = { 'prediction_success': False }
rendered = template.render(data)
print(rendered)
