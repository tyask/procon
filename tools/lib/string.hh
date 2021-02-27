#ifndef STRING_HH
#define STRING_HH

#include <bits/stdc++.h>
namespace {
using namespace std;

template<typename T=string> vector<T> split(const string& s) {
    stringstream ss(s);
    vector<T> res;
    T t;
    while (ss >> t) res.push_back(t);
    return res;
}

}

#endif