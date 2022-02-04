#pragma once

#include "common.hh"

TEMPLATE(N=ll) struct matrix : vvec<ll> {
    matrix(vvec<ll> v) : vvec(v) {};
    matrix() {};

}