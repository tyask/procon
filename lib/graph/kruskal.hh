#pragma once

#include "common.hh"
#include "unionfind.hh"


struct kruskal {
    struct edge {int u, v; ll cost; };

    int n; // 頂点数
    vec<edge> es;

    kruskal(int n) : n(n) {}

    kruskal& add(edge e) {
        es.push_back(e);
        return *this;
    }

    vec<edge> run() {
        sort(rng(es), [](auto e1, auto e2){return e1.cost < e2.cost;});
        unionfind uf(n);
        vec<edge> ret;
        each(e, es) if (uf.unite(e.u, e.v)) ret.PB(e);
        return ret;
    }
};
