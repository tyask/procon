#pragma once

#include "common.hh"

namespace {

struct bellman_ford {
    struct edge{ int from, to; ll cost; };

    int n;
    vec<edge> es;
    vec<ll> d, prev;

    bellman_ford(int n) : n(n) {};

    bellman_ford& add(edge e) {
        assert(0<=e.from && e.from<n && 0<=e.to && e.to<n);
        es.push_back(e);
        return *this;
    }

    bool run(int s) {
        assert(0<=s && s<n);
        d.resize(n, inf<ll>);
        prev.resize(n, -1);
        d[s] = 0;
        int cnt = 0;
        while (cnt < n) {
            bool updated = false;
            for (edge& e : es) {
                ll cost = d[e.from] + e.cost;
                if (d[e.from] != inf<ll> &&  cost < d[e.to]) {
                    d[e.to] = cost;
                    updated = true;
                    break;
                }
            }

            if (!updated) break;
            cnt++;
        }

        return cnt == n;
    }

    ll shortest_path(int t) { return d[t]; }

    vector<int> restore_shortest_path(int t) {
        vector<int> path;
        while(t!=-1) path.PB(t), t=prev[t];
        return reverse(path);
    }

};

}