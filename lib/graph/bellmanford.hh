#ifndef BELLMANFORD_HH
#define BELLMANFORD_HH

#include <bits/stdc++.h>
namespace {
using namespace std;

struct bellman_ford {
    using ll = long long;
    struct edge{ int from, to; ll cost; };
    template<typename T> using vec = vector<T>;
    const ll LINF = LLONG_MAX/3;

    int n;
    vec<edge> es;
    vec<ll> d;
    vec<ll> prev;

    bellman_ford(int n) : n(n) {};

    bellman_ford& add(edge e) {
        assert(0<=e.from && e.from<n && 0<=e.to && e.to<n);
        es.push_back(e);
        return *this;
    }

    bool run(int s) {
        assert(0<=s && s<n);
        d.resize(n, LINF);
        prev.resize(n, -1);
        d[s] = 0;
        int cnt = 0;
        while (cnt < n) {
            bool updated = false;
            for (edge& e : es) {
                ll cost = d[e.from] + e.cost;
                if (d[e.from] != LINF &&  cost < d[e.to]) {
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

    vector<int> shortest_path(int t) {
        vector<int> path;
        for (; t != -1; t = prev[t]) path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }

};

}

#endif