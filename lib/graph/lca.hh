#pragma once

#include "common.hh"

struct LCA {
    LCA(const graph<ll>& g, ll root=0) {
        ll n = sz(g), h = highest_bit(n);
        parent.assign(h, vec<ll>(n,-1));
        dist.assign(n,-1);

        auto dfs = [&](auto self, ll v, ll p, ll d) -> void {
            parent[0][v] = p;
            dist[v] = d;
            each(n, g[v]) if (n!=p) self(self, n, v, d+1);
        };
        dfs(dfs, root, -1, 0);

        rep(k,h-1) rep(v,n) {
            if (parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }

    ll query(ll u, ll v) const {
        if (dist[u]<dist[v]) swap(u, v);
        ll n = parent.size();
        rep(k,n) if((dist[u]-dist[v])>>k&1) u=parent[k][u];
        if (u==v) return u;

        rrep(k,n) if(parent[k][u]!=parent[k][v]) u=parent[k][u], v=parent[k][v];

        return parent[0][u];
    }

private:
    vvec<ll> parent; // parent[k][u]:=uの2^k先の親
    vec<ll> dist; // dist[u]:=uのrootからの距離

    ll highest_bit(ll n) { ll k = 1; while((1<<k)<n) k++; return k; }
};
