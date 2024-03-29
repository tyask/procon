#pragma once

#include "common.hh"

namespace {

template<ll M> struct modint {
    using mint = modint<M>;
    static constexpr ll MOD = M;

    ll v;

    modint(ll v=0):v((v%MOD+MOD)%MOD){}

    ll val() const { return v; }

    mint operator-() const { return mint(-v);}
    mint& operator++() { v++; if (v == MOD) v = -1; return *this; }
    mint& operator--() { if (v == -1) v = MOD; v--; return *this; }
    mint operator++(int) { mint r = *this; ++*this; return r; }
    mint operator--(int) { mint r = *this; --*this; return r; }

    mint& operator+=(mint a) { if ((v += a.v) >= MOD) v -= MOD; return *this; }
    mint& operator-=(mint a) { if ((v += MOD-a.v) >= MOD) v -= MOD; return *this; }
    mint& operator*=(mint a) { (v *= a.v) %= MOD; return *this;}
    mint& operator/=(mint a) { return *this *= a.inv();}
    mint operator+(mint a) const { return mint(*this) += a;}
    mint operator-(mint a) const { return mint(*this) -= a;}
    mint operator*(mint a) const { return mint(*this) *= a;}
    mint operator/(mint a) const { return mint(*this) /= a;}

    mint pow(ll t) const { if (t==0) return 1; mint a = pow(t>>1); a *= a; if (t&1) a *= *this; return a; }
    mint inv() const { return pow(MOD-2);}

    bool operator==(mint a) const { return val()==a.val(); }
    bool operator!=(mint a) const { return !(*this == a); }
    bool operator< (mint a) const { return val()<a.val(); }
    bool operator> (mint a) const { return val()>a.val(); }
    bool operator<=(mint a) const { return val()<=a.val(); }
    bool operator>=(mint a) const { return val()>=a.val(); }
};

template<ll M> istream& operator>>(istream& is, modint<M> m) { return is >> m.val();}
template<ll M> ostream& operator<<(ostream& os, modint<M> m) { return os << m.val();}

using mint = modint<1000000007>;
// using mint = modint<998244353>;

TEMPLATE(MINT) struct combination {
    vec<MINT> facts, ifacts;

    combination(int n):facts(n+1),ifacts(n+1) {
        assert(n < MINT::MOD);
        facts[0] = 1;
        rep(i,1,n+1) facts[i] = facts[i-1]*i;
        ifacts[n] = facts[n].inv();
        rrep(i,1,n+1) ifacts[i-1] = ifacts[i]*i;
    }

    MINT operator()(int n, int k) const {
        assert(n < MINT::MOD);
        if (k < 0 || k > n) return 0;
        return fact(n)*ifact(k)*ifact(n-k);
    }

    MINT fact(int k) const { return facts.at(k); }
    MINT ifact(int k) const { return ifacts.at(k); }

};

TEMPLATE(MINT) using comb = combination<MINT>;

}