#ifndef COMBINATION_HH
#define COMBINATION_HH

#include <bits/stdc++.h>
#include "modint.hh"

namespace {

template<typename MINT>
struct combination {
private:
    std::vector<MINT> fact, ifact;

public:
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < MINT::MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }

    MINT operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};

template<typename MINT> using comb = combination<MINT>;

}

#endif