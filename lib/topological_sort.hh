#ifndef TOPOLOGICAL_SORT_HH
#define TOPOLOGICAL_SORT_HH

#include "common.hh"

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

#endif