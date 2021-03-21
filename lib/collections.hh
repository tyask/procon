#ifndef COLLECTIONS_HH
#define COLLECTIONS_HH

#include <bits/stdc++.h>

using namespace std;

template<typename T> set<T> andset(const set<T>& a, const set<T>& b) {
    set<T> r;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.end()));
    return r;
}

template<typename T> set<T> orset(const set<T>& a, const set<T>& b) {
    set<T> r;
    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.end()));
    return r;
}

#endif