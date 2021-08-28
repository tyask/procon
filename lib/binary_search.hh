#ifndef BINARY_SEARCH_HH
#define BINARY_SEARCH_HH

#include <bits/stdc++.h>

using namespace std;
namespace fumin {
template<typename T> int binary_search(int ng, int ok, function<bool(T)> is_ok) {
    while (abs(ok-ng)>1) {
        int mid = (ok+ng) / 2;
        if (is_ok(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

}

#endif