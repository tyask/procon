#ifndef UNIONFIND_HH
#define UNIONFIND_HH

#include "common.hh"
namespace {

struct unionfind {
    vec<ll> d;

    unionfind(ll n): d(n,-1) {}

    ll find(ll x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    bool unite(ll x, ll y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) std::swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(ll x, ll y) { return find(x) == find(y);}
    ll size(ll x) { return -d[find(x)];}
    void reset() { fill(d.begin(), d.end(), -1); }

};

vvec<ll> groups(unionfind& uf) {
    ll n = uf.d.size();
    vec<ll> leader_buf(n), group_size(n);

    rep(n) leader_buf[i] = uf.find(i), group_size[leader_buf[i]]++;

    vvec<ll> res(n);
    rep(n) res[i].reserve(group_size[i]);
    rep(n) res[leader_buf[i]].push_back(i);

    auto it = remove_if(rng(res), [&](auto& v){ return v.empty(); });
    res.erase(it, res.end());

    return res;
}


}

#endif