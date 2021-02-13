#include <bits/stdc++.h>
#include "modint.hh"
#include "combination.hh"
#include "unionfind.hh"

using namespace std;

int main() {
    using mint = mint1000000007;
    mint m(200);
    cout << m << endl;

    combination<mint> comb(10);
    cout << comb(5, 2) << endl;

    UnionFind uf(10);
    uf.unite(1, 2);
    cout << uf.find(0) << endl;
    cout << uf.find(1) << endl;
    cout << uf.find(2) << endl;
    cout << uf.same(0, 1) << endl;
    cout << uf.same(1, 2) << endl;
    
}