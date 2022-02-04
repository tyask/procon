#pragma once

#include "common.hh"

namespace {

struct dijkstra {
    struct edge{ll from, to, cost; };

    int n;
    vec<vec<edge>> g;
    vec<ll> d, prev;

    dijkstra(int n) : n(n), g(n) {};

    dijkstra& add(edge e) {
        assert(0<=e.from && e.from<n && 0<=e.to && e.to<n);
        g.at(e.from).push_back(e);
        return *this;
    }

    void run(int s) {
        assert(0<=s && s<n);
        using P = pair<ll, int>; // cost, node
        pqg<P> que;
        d.assign(n, inf<ll>);
        prev.assign(n, -1);
        d[s] = 0;
        que.emplace(0, s);
        while (que.size()) {
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

    ll operator[](int t) { return d[t]; }

    vec<int> restore_shortest_path(int t) {
        vec<int> path;
        while (t!=-1) path.PB(t), t=prev[t];
        return reverse(path);
    }

};

}
