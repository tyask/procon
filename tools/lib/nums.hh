#ifndef NUMS_HH
#define NUMS_HH

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n_digits(ll n) {
    int d = 0;
    while (n > 0) {
        d++;
        n /= 10;
    }

    return d;
}

bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }

    return true;
}

set<ll> divisors(ll n) {
    set<ll> ret;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ret.insert(i);
        if (i * i != n) ret.insert(n / i);
    }

    return ret;
}

map<ll, ll> prime_fact(ll n) {
    map<ll, ll> ret;
    for (ll d = 2; d * d <= n; ++d) {
        ll e = 0;
        while (n % d == 0) {
            e++;
            n /= d;
        }
        if (e > 0) ret[d] = e;
    }

    if (n != 1) ret[n] = 1;
    return ret;
}

#endif