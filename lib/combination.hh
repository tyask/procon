#ifndef COMBINATION_HH
#define COMBINATION_HH

#include <bits/stdc++.h>
#include "modint.hh"

namespace mod {

template<typename MINT>
struct combination {
private:
    std::vector<MINT> facts, ifacts;

public:
    combination(int n):facts(n+1),ifacts(n+1) {
        assert(n < MINT::MOD);
        facts[0] = 1;
        for (int i = 1; i <= n; ++i) facts[i] = facts[i-1]*i;
        ifacts[n] = facts[n].inv();
        for (int i = n; i >= 1; --i) ifacts[i-1] = ifacts[i]*i;
    }

    MINT operator()(int n, int k) const {
        assert(n < MINT::MOD);
        if (k < 0 || k > n) return 0;
        return fact(n)*ifact(k)*ifact(n-k);
    }

    MINT fact(int k) const { return facts.at(k); }
    MINT ifact(int k) const { return ifacts.at(k); }

};

template<typename MINT> using comb = combination<MINT>;

}

namespace math {

// パスカルの三角形によりnCkを計算
struct combination {
    using ll = long long;
    template<typename T> using vec = std::vector<T>;
    vec<vec<ll>> m;

    combination(int n) : m(n+1, vec<ll>(n+1)) {
        m[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                m[i+1][j] += m[i][j];
                m[i+1][j+1] += m[i][j];
            }
        }
    }

    ll operator()(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return m[n][k];
    }

};

}

#endif