#ifndef KRASCAL_HH
#define KRASCAL_HH

#include <bits/stdc++.h>
#include "unionfind.hh"

using namespace std;

struct kruskal {
    using ll = long long;
    struct edge {int u, v; ll cost; };

    int n; // 頂点数
    vector<edge> es;

    kruskal(int n) : n(n) {}

    kruskal& add(edge e) {
        es.push_back(e);
        return *this;
    }

    vector<edge> run() {
        sort(es.begin(), es.end(), [](auto& e1, auto& e2){return e1.cost < e2.cost;});
        unionfind uf(n);
        vector<edge> ret;
        for (edge e : es) {
            if (!uf.same(e.u, e.v)) {
                uf.unite(e.u, e.v);
                ret.push_back(e);
            }
        }

        return ret;
    }
};

#endif