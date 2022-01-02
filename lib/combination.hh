#pragma once

#include "common.hh"
#include "modint.hh"

namespace mod {

TEMPLATE(MINT) struct combination {
    vec<MINT> facts, ifacts;

    combination(int n):facts(n+1),ifacts(n+1) {
        assert(n < MINT::MOD);
        facts[0] = 1;
        rep(i,1,n+1) facts[i] = facts[i-1]*i;
        ifacts[n] = facts[n].inv();
        rrep(i,1,n+1) ifacts[i-1] = ifacts[i]*i;
    }

    MINT operator()(int n, int k) const {
        assert(n < MINT::MOD);
        if (k < 0 || k > n) return 0;
        return fact(n)*ifact(k)*ifact(n-k);
    }

    MINT fact(int k) const { return facts.at(k); }
    MINT ifact(int k) const { return ifacts.at(k); }

};

TEMPLATE(MINT) using comb = combination<MINT>;

}

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