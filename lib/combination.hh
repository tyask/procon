#pragma once

#include "common.hh"

namespace math {

// パスカルの三角形によりnCkを計算
struct combination {
    vvec<ll> m;

    combination(int n) : m(n+1, vec<ll>(n+1)) {
        m[0][0] = 1;
        rep(i,n) rep(j,n) {
            m[i+1][j] += m[i][j];
            m[i+1][j+1] += m[i][j];
        }
    }

    ll operator()(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return m[n][k];
    }

};

}