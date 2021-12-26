#ifndef SEGTREE_HH
#define SEGTREE_HH

#include "common.hh"
namespace {

template<typename T=ll> struct segtree {
    using func = function<T(T,T)>;
    ll n;
    vec<T> dat;
    func fx;
    T e;
    segtree(ll n, func fx, T e) : n(pow2(n)), dat(n*4, e), fx(fx), e(e) {}

    void update(ll i, T v) {
        i += n - 1;
        dat[i] = v;
        while (i>0) {
            i = parent(i);
            dat[i] = fx(dat[left_child(i)], dat[right_child(i)]);
        }
    }

    T operator[](ll i) { return (*this)(i, i+1); };

    // [a, b)
    T operator()(ll a, ll b) { return query_sub(a, b, 0, 0, n); }

private:
    T query_sub(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return dat[k];

        ll vl = query_sub(a, b, k*2+1, l, (l+r)/2);
        ll vr = query_sub(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }

    ll pow2(ll capacity) { ll x = 1; while (capacity>x) x*=2; return x; }

    ll parent(ll i) { return (i - 1) / 2; }
    ll left_child(ll i) { return i * 2 + 1; }
    ll right_child(ll i) { return i * 2 + 2; }
};

struct RMQ : segtree<ll> {
    RMQ(ll n) : segtree<ll>(n, [](ll x, ll y){return min(x,y);}, inf<ll>) {}
};

}

#endif