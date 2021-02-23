#ifndef MODINT_HH
#define MODINT_HH

#include <bits/stdc++.h>
namespace {

template<long long M>
struct modint {
private:
    using ll = long long;
    using mint = modint<M>;

    ll v;
public:
    static constexpr ll MOD = M;
    modint(ll v=0):v((v%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-v);}
    mint& operator+=(const mint a) {
        if ((v += a.v) >= MOD) v -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((v += MOD-a.v) >= MOD) v -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) { (v *= a.v) %= MOD; return *this;}
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

    long long val() const { return v; }

};

template<long long MOD> using mint = modint<MOD>;
template<long long M> bool operator==(mint<M> a, mint<M> b) { return a.val() == b.val(); }
template<long long M> bool operator!=(mint<M> a, mint<M> b) { return a.val() != b.val(); }
template<long long M> bool operator< (mint<M> a, mint<M> b) { return a.val() < b.val(); }
template<long long M> bool operator> (mint<M> a, mint<M> b) { return a.val() > b.val(); }
template<long long M> bool operator<=(mint<M> a, mint<M> b) { return a.val() <= b.val(); }
template<long long M> bool operator>=(mint<M> a, mint<M> b) { return a.val() >= b.val(); }

template<long long M> std::istream& operator>>(std::istream& is, mint<M>& m) { return is >> m.val();}
template<long long M> std::ostream& operator<<(std::ostream& os, const mint<M>& m) { return os << m.val();}

using mint1000000007 = mint<1000000007>;
using mint998244353  = mint<998244353>;

// ll powmod(ll n, ll k, ll m){ ll ans = 1; while(k){ if(k & 1) (ans *= n) %= m; (n *= n) %= m; k >>= 1; } return ans; }
// ll mod(ll n, ll m) { ll r = n % m; return (r < 0) ? r + m : r; }

}

#endif