#ifndef DIJKSTRA_HH
#define DIJKSTRA_HH

#include <bits/stdc++.h>
namespace {
using namespace std;
template<class T, class U> bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }

struct dijkstra {
    using ll = long long;
    struct edge{ ll to; ll cost; };
    template<typename T> using vec = vector<T>;
    const ll LINF = LLONG_MAX/3;

    int n;
    vec<vec<edge>> g;
    vec<ll> d;
    vec<ll> prev;

    dijkstra(int n) : n(n), g(n) {};

    dijkstra& add(ll from, edge e) {
        assert(0<=from && from<n && 0<=e.to && e.to<n);
        g.at(from).push_back(e);
        return *this;
    }

    void run(int s) {
        assert(0<=s && s<n);
        using P = pair<ll, int>; // cost, node
        priority_queue<P, vec<P>, greater<P>> que;
        d.resize(n, LINF);
        prev.resize(n, -1);
        d[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [cost, v] = que.top(); que.pop();
            if (d[v] < cost) continue;
            for (edge e : g[v]) {
                if (chmin(d[e.to], d[v] + e.cost)) {
                    que.emplace(d[e.to], e.to);
                    prev[e.to] = v;
                }
            }
        }
    }

    ll shortest_path(int t) {
        return d[t];
    }

    vector<int> restore_shortest_path(int t) {
        vector<int> path;
        for (; t != -1; t = prev[t]) path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }

};

}

#endif