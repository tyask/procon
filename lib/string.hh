#ifndef STRING_HH
#define STRING_HH

#include <bits/stdc++.h>
namespace {
using namespace std;
using str = string;
using ll  = long long;
template<typename T> using vec = vector<T>;


template<typename T=string> vector<T> split(const string& s) {
    stringstream ss(s);
    vector<T> res;
    T t;
    while (ss >> t) res.push_back(t);
    return res;
}

vec<pair<char, ll>> runlength_encoding(const str& s) {
    vec<pair<char, ll>> ps;
    if (s.empty()) return ps; 

    ps.emplace_back(s[0], 1);
    for (int i = 1, n = s.size(); i < n; ++i) {
        if (s[i]!=s[i-1]) ps.emplace_back(s[i], 0);
        ps.back().second++;
    }

    return ps;
}

}

#endif