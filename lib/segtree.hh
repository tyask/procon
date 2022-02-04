#pragma once

#include <atcoder/all>
#include "common.hh"

namespace {
struct segtree {
    using N = ll;
    using func = function<N(N,N)>;
    segtree(ll n, func fx, N e) : n(ceilpow2(n)), dat(n*4, e), fx(fx), e(e) {}

    void update(ll i, N v) {
        i += n - 1;
        dat[i] = v;
        while (i>0) {
            i = par(i);
            dat[i] = fx(dat[lch(i)], dat[rch(i)]);
        }
    }

    N operator[](ll i) { return (*this)(i, i+1); };

    // [a, b)
    N operator()(ll a, ll b) { return query_sub(a, b, 0, 0, n); }

private:
    ll n;
    vec<N> dat;
    func fx;
    N e;

    N query_sub(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return dat[k];

        N vl = query_sub(a, b, k*2+1, l, (l+r)/2);
        N vr = query_sub(a, b, k*2+2, (l+r)/2, r);
        return fx(vl, vr);
    }

    ll ceilpow2(ll capacity) { ll x = 1; while (capacity>x) x*=2; return x; }

    ll par(ll i) { return (i - 1) / 2; }
    ll lch(ll i) { return i * 2 + 1; }
    ll rch(ll i) { return i * 2 + 2; }
};

struct Rmq : segtree {
    Rmq(ll n) : segtree(n, [](ll x, ll y){return min(x,y);}, inf<ll>) {}
};

// 区間加算・区間最小値
namespace segtree {
using S = ll;
using F = ll;

S op(S a, S b){ return std::min(a, b); }
S e(){ return inf<ll>; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

using segtree = atcoder::lazy_segtree<S,op,e,F,mapping,composition,id>;
}

// 区間加算・区間最大値
namespace segtree {
using S = ll;
using F = ll;

S op(S a, S b){ return max(a, b); }
S e(){ return -inf<ll>; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

using segtree = atcoder::lazy_segtree<S,op,e,F,mapping,composition,id>;
}

// 区間加算・区間和
namespace segtree {
struct S { ll value, size; };
using F = ll;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

struct segtree : atcoder::lazy_segtree<S,op,e,F,mapping,composition,id> {
    segtree(ll n) : atcoder::laxy_segtree(vec<S>(n, {0, 1}));
};
}

// 区間変更・区間最小値
namespace segtree {
using S = ll;
using F = ll;

S op(S a, S b){ return min(a, b); }
S e(){ return inf<ll>; }
F id(){ return inf<ll>; }
S mapping(F f, S x){ return f == id() ? x : f; }
F composition(F f, F g){ return f == id() ? g : f; }

using segtree = atcoder::lazy_segtree<S,op,e,F,mapping,composition,id>;
}

// 区間変更・区間最大値
namespace segtree {
using S = ll;
using F = ll;

S op(S a, S b){ return max(a, b); }
S e(){ return -inf<ll>; }
F id(){ return inf<ll>; }
S mapping(F f, S x){ return f == id() ? x : f; }
F composition(F f, F g){ return f == id() ? g : f; }

using segtree = atcoder::lazy_segtree<S,op,e,F,mapping,composition,id>;
}

// 区間変更・区間和
namespace segtree {
struct S { ll value, size; };
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
F id(){ return inf<ll>; }
S mapping(F f, S x){ return f==id() ? x : x.value=f*x.size(); }
F composition(F f, F g){ return f==id() ? g : f); }

struct segtree : atcoder::lazy_segtree<S,op,e,F,mapping,composition,id> {
    segtree(ll n) : atcoder::laxy_segtree(vec<S>(n, {0, 1}));
};
}
