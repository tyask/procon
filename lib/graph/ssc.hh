#pragma once
#include "common.hh"

// 強連結成分分解(双方向に行き来できる点をグルーピングする)を行う.
// O(V+E)
// gは対象の有向グラフ
vvec<ll> ssc(const vvec<ll>& g) {
    const ll N = sz(g);

    // 逆向き有向グラフ構築
    vvec<ll> h(N);
    rep(N) each(v,g[i]) h[v].PB(i);

    // dfs1
    vec<ll> vis(N), t;
    auto dfs = [&](auto self, ll v) {
        if (vis[v]) return;
        vis[v]=1;
        each(n,g[v]) self(self,n);
        t.PB(v);
    };
    rep(v,N) dfs(dfs,v);

    // dfs2 (grouping)
    vec<ll> gn(N,-1);
    ll gi = 0;
    auto rdfs = [&](auto self, ll v) {
        if (gn[v]>=0) return;
        gn[v]=gi;
        each(n,h[v]) self(self,n);
    };

    reverse(t);
    each(v,t) if(gn[v]<0) rdfs(rdfs,v), gi++;

    vvec<ll> group(gi);
    rep(N) group[gn[i]].PB(i);

    return group;
}