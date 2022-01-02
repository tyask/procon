#pragma once

#include "common.hh"

TEMPLATE(Cont) auto andset(const Cont& c1, const Cont& c2) {
    set<typename Cont::value_type> a(rng(c1)), b(rng(c2));
    Cont ret;
    set_intersection(rng(a), rng(b), inserter(ret, ret.end()));
    return ret;
}

TEMPLATE(Cont) auto orset(const Cont& c1, const Cont& c2) {
    set<typename Cont::value_type> a(rng(c1)), b(rng(c2));
    Cont ret;
    set_union(rng(a), rng(b), inserter(ret, ret.end()));
    return ret;
}

// 最長増加部分列(longest increase sequence)の長さを返す. O(NlogN)
// dp[i]:=その時点での要素数iの部分列の最終要素の最小値.
// 最終要素を小さく保つことで、その後の数を受け入れやすくする気持ち.
ll LIS(const vec<ll>& v) {
    vec<ll> dp(sz(v), inf<ll>);
    each(n,v) *lower_bound(rng(dp),n) = n;
    return find(rng(dp),inf<ll>)-dp.begin();
}

vec<ll> topological_sort(const vvec<ll>& g) {
    vec<ll> ret;
    ll n = g.size();

    vec<ll> deg(n);
    rep(n) each(e, g[i]) deg[e]++;
    
    queue<ll> q;
    rep(n) if(deg[i]==0) q.push(i);

    while (q.size()) {
        ll v = pop(q);
        ret.PB(v);
        each(e, g[v]) if (--deg[e]==0) q.push(e);
    }

    return ret;
}

