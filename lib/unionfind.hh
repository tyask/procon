#ifndef UNIONFIND_HH
#define UNIONFIND_HH

#include <bits/stdc++.h>
namespace {

struct UnionFind {
    template<typename T> using vec = std::vector<T>;
    template<typename K, typename V> using map = std::map<K, V>;
    vec<int> d;

    UnionFind(int n): d(n,-1) {}

    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) std::swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -d[find(x)];}
    void reset() { fill(d.begin(), d.end(), -1); }

    vec<vec<int>> groups() {
        int n = d.size();
        vec<int> leader_buf(n), group_size(n);
        for (int i = 0; i < n; i++) {
            leader_buf[i] = find(i);
            group_size[leader_buf[i]]++;
        }
        vec<vec<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const vec<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
};

}

#endif