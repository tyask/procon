#ifndef GRID_HH
#define GRID_HH

#include <bits/stdc++.h>

namespace {

struct In {
    int h, w;
    In(int h, int w) : h(h), w(w) {}
    bool operator()(int i, int j) { return 0<=i && i<h && 0<=j && j<w; }
};

}

#endif