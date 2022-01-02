#pragma once

#include "common.hh"
namespace {

// 0-indexed
struct fenwick_tree {
    fenwick_tree(ll n) : dat(n), n(n) {}

    // O(logN)
    void add(ll p, ll v) {
        assert(0<=p && p<n);
        p++;
        while (p<=n) dat[p-1]+=v, p+=lsb(p);
    }

    ll get(ll p) { return sum(p, p+1); }
    void set(ll p, ll v) { add(p, v-get(p)); }

    // sum of [l, r) O(logN)
    ll sum(ll l, ll r) { return sum(r)-sum(l); }

    // sum of [0, r) O(logN)
    ll sum(ll p) {
        assert(0<=p && p<n);
        ll ret = 0;
        while (p>0) ret+=dat[p-1], p-=lsb(p);
        return ret;
    }

    ll lower_bound(ll v) {
        if (v <= 0) return 0;
        ll x = 0;
        for (ll k = largest_power_of_2(n); k>0; k/=2) {
            if (x+k<=n&&dat[x+k-1]<v) v-=dat[x+k-1], x+=k;
        }
        return x;
    }

private:
    vec<ll> dat;
    ll n;
    ll lsb(ll n) { return n & -n; }
    ll largest_power_of_2(ll n) { ll r = 1; while (r*2<=n) r*=2; return r; }
};

struct fenwick_tree_2d {
    fenwick_tree_2d(ll n, ll m) : dat(n, vec<ll>(m)), n(n), m(m) {}

    void add(ll i, ll j, ll v) {
        assert(0<=i&&i<n && 0<=j&&j<m);
        i++, j++;
        while (i<=n) {
            while (j<=m) dat[i-1][j-1]+=v, j+=lsb(j);
            i+=lsb(i);
        }
    }

    ll sum(ll i1, ll j1, ll i2, ll j2) {
        return sum(i2,j2) - sum(i1,j1);
    }

    ll sum(ll i, ll j) {
        assert(0<=i&&i<n && 0<=j&&j<m);
        ll ret = 0;
        while (i>0) {
            while (j>0) ret+=dat[i-1][j-1], j-=lsb(j);
            i-=lsb(i);
        }
        return ret;
    }

private:
    vec<vec<ll>> dat;
    ll n, m;
    ll lsb(ll n) { return n & -n; }
};

}