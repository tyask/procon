#ifndef COLLECTIONS_HH
#define COLLECTIONS_HH

#include <bits/stdc++.h>

using namespace std;

template<typename Cont> set<typename Cont::value_type> andset(const Cont& c1, const Cont& c2) {
    using T = typename Cont::value_type;
    set<T> a = set<T>(c1.begin(), c1.end());
    set<T> b = set<T>(c2.begin(), c2.end());

    set<T> r;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.end()));
    return r;
}

template<typename Cont> set<typename Cont::value_type> orset(const Cont& c1, const Cont& c2) {
    using T = typename Cont::value_type;
    set<T> a = set<T>(c1.begin(), c1.end());
    set<T> b = set<T>(c2.begin(), c2.end());

    set<T> r;
    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.end()));
    return r;
}

#endif