#pragma once

#include "common.hh"

namespace {

struct dijkstra {
    struct edge{ ll to; ll cost; };

    int n;
    vec<vec<edge>> g;
    vec<ll> d, prev;

    dijkstra(int n) : n(n), g(n) {};

    dijkstra& add(ll from, edge e) {
        assert(0<=from && from<n && 0<=e.to && e.to<n);
        g.at(from).push_back(e);
        return *this;
    }

    void run(int s) {
        assert(0<=s && s<n);
        using P = pair<ll, int>; // cost, node
        pqg<P> que;
        d.resize(n, inf<ll>);
        prev.resize(n, -1);
        d[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [cost, v] = pop(que);
            if (d[v] < cost) continue;
            for (edge e : g[v]) {
                if (chmin(d[e.to], d[v] + e.cost)) {
                    que.emplace(d[e.to], e.to);
                    prev[e.to] = v;
                }
            }
        }
    }

    ll shortest_path(int t) { return d[t]; }

    vec<int> restore_shortest_path(int t) {
        vec<int> path;
        while (t!=-1) path.PB(t), t=prev[t];
        return reverse(path);
    }

};

}
