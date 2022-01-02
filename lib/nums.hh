#pragma once

#include "common.hh"

bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i*i <= n; ++i) if (n%i==0) return false;
    return true;
}

vec<ll> divisors(ll n) {
    vec<ll> ret;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ret.PB(i);
        if (i * i != n) ret.PB(n / i);
    }
    sort(ret);
    return ret;
}

map<ll, int> prime_fact(ll n) {
    map<ll, int> ret;
    for (ll d = 2; d * d <= n; ++d) {
        int e = 0;
        while (n % d == 0) { e++; n /= d; }
        if (e != 0) ret[d] = e;
    }

    if (n != 1) ret[n] = 1;
    return ret;
}
