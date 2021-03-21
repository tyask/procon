#ifndef NUMS_HH
#define NUMS_HH

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename N> int n_digits(N n) {
    int d = 0;
    while (n > 0) { d++; n /= 10; }
    return d;
}

template<typename N> bool is_prime(N n) {
    if (n == 1) return false;
    for (N i = 2; i*i <= n; ++i) if (n % i == 0) return false;
    return true;
}

template<typename N> set<N> divisors(N n) {
    set<ll> ret;
    for (N i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ret.insert(i);
        if (i * i != n) ret.insert(n / i);
    }

    return ret;
}

template<typename N> map<N, int> prime_fact(N n) {
    map<N, int> ret;
    for (N d = 2; d * d <= n; ++d) {
        int e = 0;
        while (n % d == 0) { e++; n /= d; }
        if (e != 0) ret[d] = e;
    }

    if (n != 1) ret[n] = 1;
    return ret;
}

#endif