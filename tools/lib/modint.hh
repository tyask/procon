#ifndef MODINT_HH
#define MODINT_HH

#include <bits/stdc++.h>
namespace {

template<long long M>
struct modint {
private:
    using ll = long long;
    using mint = modint<M>;

    template<ll M2> friend std::istream& operator>>(std::istream& is, modint<M2>& m);
    template<ll M2> friend std::ostream& operator<<(std::ostream& is, const modint<M2>& m);

    ll val;
public:
    static constexpr ll MOD = M;
    modint(ll val=0):val((val%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-val);}
    mint& operator+=(const mint a) {
        if ((val += a.val) >= MOD) val -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((val += MOD-a.val) >= MOD) val -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) { (val *= a.val) %= MOD; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(MOD-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};

template<long long MOD> std::istream& operator>>(std::istream& is, modint<MOD>& m) { return is >> m.val;}
template<long long MOD> std::ostream& operator<<(std::ostream& os, const modint<MOD>& m) { return os << m.val;}

template<long long MOD> using mint = modint<MOD>;
using mint1000000007 = mint<1000000007>;
using mint998244353  = mint<998244353>;

}

#endif