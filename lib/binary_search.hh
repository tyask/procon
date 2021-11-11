#ifndef BINARY_SEARCH_HH
#define BINARY_SEARCH_HH

#include <bits/stdc++.h>

namespace fumin {

using namespace std;

template<typename N> N bin_search(N ng, N ok, function<bool(N)> isok) {
    while (abs(ok-ng)>1) {
        N mid = (ok+ng) / 2;
        if (isok(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

}

#endif