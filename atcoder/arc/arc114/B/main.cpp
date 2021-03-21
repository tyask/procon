#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"

#include <bits/stdc++.h>

namespace {
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define overload2(_1,_2,name,...) name

#define template1(t) template<typename t>
#define template2(t, u) template<typename t, typename u>
#define template3(t, u, v) template<typename t, typename u, typename v>
#define TEMPLATE(...) overload3(__VA_ARGS__, template3, template2, template1)(__VA_ARGS__)

using namespace std;
using ll   = long long;
using ull  = unsigned long long;
using uint = unsigned int;
using str  = string;
using pii  = pair<int, int>;
using pll  = pair<ll, ll>;
TEMPLATE(T) using vec = vector<T>;
TEMPLATE(T) using vvec = vec<vec<T>>;

const ll     LINF = LLONG_MAX/3;
const int    INF  = INT_MAX/2-100;
const double DINF = numeric_limits<double>::infinity();
const double EPS  = 1e-9;
const double PI   = 3.1415926535897932;
const int    dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int    dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

#define PB push_back
#define MP make_pair
#define FI first
#define SE second

#define INT(...)  int    __VA_ARGS__; in(__VA_ARGS__)
#define LL(...)   ll     __VA_ARGS__; in(__VA_ARGS__)
#define ULL(...)  ull    __VA_ARGS__; in(__VA_ARGS__)
#define STR(...)  string __VA_ARGS__; in(__VA_ARGS__)
#define LINE(...) string __VA_ARGS__; scan_line(__VA_ARGS__)
#define CHR(...)  char   __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...)  double __VA_ARGS__; in(__VA_ARGS__)
#define VEC(type, name, size) vec<type>  name(size);           in(name)
#define VV(type,name, h, w)   vvec<type> name(h,vec<type>(w)); in(name)

#define rep1(n)       for(int i=0; i<n; ++i)
#define rep2(i,n)     for(int i=0; i<n; ++i)
#define rep3(i,a,b)   for(int i=a; i<b; ++i)
#define rep4(i,a,b,c) for(int i=a; i<b; i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)

#define rrep1(n)       for(int i=(n)-1; i>=0;   --i)
#define rrep2(i,n)     for(int i=(n)-1; i>=0;   --i)
#define rrep3(i,a,n)   for(int i=(n)-1; i>=(a); --i)
#define rrep4(i,a,n,s) for(int i=a+(n-a-1)/s*s; i>=a; i-=s)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)

#define erep1(n)       for(int i=0; i<=n; ++i)
#define erep2(i,n)     for(int i=0; i<=n; ++i)
#define erep3(i,a,n)   for(int i=a; i<=n; ++i)
#define erep4(i,a,n,s) for(int i=a; i<=n; i+=s)
#define erep(...) overload4(__VA_ARGS__,erep4,erep3,erep2,erep1)(__VA_ARGS__)

#define each(i, c) for (auto&& i : (c))
#define itr(c) for (auto it = begin(c); it != end(c); ++it)

#define rng1(i)     begin(i),   end(i)
#define rng2(i,a)   begin(i),   begin(i)+a
#define rng3(i,a,b) begin(i)+a, begin(i)+b
#define rng(...) overload3(__VA_ARGS__,rng3,rng2,rng1)(__VA_ARGS__)

TEMPLATE(T) void scan(T& a){ cin >> a; }
TEMPLATE(T) void scan(vec<T>& a, int n){ a.resize(n); for(auto&& i : a) scan(i); }
TEMPLATE(T) void scan(vec<T>& a){ scan(a, a.size()); }
TEMPLATE(T) void scan(vvec<T>& a){ for(auto&& v : a) scan(v); }
void scan_line(string& s) { getline(cin, s); }
void in(){}
TEMPLATE(Head, ...Tail) void in(Head& head, Tail&... tail){ scan(head); in(tail...); }

TEMPLATE(T) void out(ostream& os, T&& t) { os << t << endl; }
TEMPLATE(T) void outh(ostream& os, T&& t) { os << t << " "; }
TEMPLATE(T, ...Args) void out(ostream& os, T&& head, Args&&... tail) { outh(os, head); out(os, tail...); };
TEMPLATE(T, ...Args) void out(T&& head, Args&&... tail) { out(cout, head, tail...); }
const char* space_or_empty[] = {"", " "};
TEMPLATE(Cont) ostream& write(ostream& os, const Cont& c) { itr(c) os << space_or_empty[it!=c.begin()] << *it; return os; }

TEMPLATE(T)    ostream& operator<<(ostream& os, const vector<T>& c) { return write(os, c); }
TEMPLATE(T)    ostream& operator<<(ostream& os, const list<T>& c) { return write(os, c); }
TEMPLATE(T)    ostream& operator<<(ostream& os, const set<T>& c) { return write(os, c); }
TEMPLATE(K, V) ostream& operator<<(ostream& os, const map<K, V>& c) { return write(os, c); }
TEMPLATE(T, U) ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << p.first << ':' << p.second; }

TEMPLATE(Cont) auto sum(const Cont& c) { return accumulate(rng(c), 0LL); }
TEMPLATE(T)    auto sum(const initializer_list<T>& c) { return sum(vec<T>(c)); }
TEMPLATE(Cont) auto max(const Cont& c) { return *max_element(rng(c)); }
TEMPLATE(Cont) auto min(const Cont& c) { return *min_element(rng(c)); }
TEMPLATE(Cont) auto sort(Cont& c) { sort(rng(c)); }
TEMPLATE(Cont, Comp) auto sort(Cont& c, Comp comp) { sort(rng(c), comp); }
TEMPLATE(Cont) auto reverse(Cont& c) { reverse(rng(c)); }
TEMPLATE(T, U) bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
TEMPLATE(T, U) bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
TEMPLATE(T) vec<T> cumsum(const vec<T>& v) { vec<T> s(v.size()+1, 0); rep(v.size()) s[i+1] = s[i] + v[i]; return s; }
TEMPLATE(T) vec<T> uniq(const vec<T>& v) { set<T> s(rng(v)); return vec<T>(rng(s)); }
TEMPLATE(T, S)    T pop(queue<T, S>& q) { T t = q.front(); q.pop(); return t; }
TEMPLATE(T, S, C) T pop(priority_queue<T, S, C>& q) { T t = q.top(); q.pop(); return t; }

TEMPLATE(N) N gcd(N a, N b){ while(b){ N c = b; b = a % b; a = c; } return a; }
TEMPLATE(N) N lcm(N a, N b){ if(!a || !b) return 0; return a / gcd(a, b) * b; }
TEMPLATE(N) N powint(N n, N k){ N ans = 1; while(k){ if(k & 1) ans *= n; n *= n; k >>= 1; } return ans; }
TEMPLATE(N) N floor(N a, N b) { return a / b; }
TEMPLATE(N) N ceil(N a, N b) { return (a + b - 1) / b; }

#define YESNO(y, n) void y(bool b=true) { out(b?#y:#n); } void n(bool b=true) { y(!b); }
YESNO(YES, NO)
YESNO(Yes, No)
YESNO(yes, no)
YESNO(POSSIBLE, IMPOSSIBLE)
YESNO(Possible, Impossible)
YESNO(possible, impossible)

}

#define __ATCODER__ 1

#if __ATCODER__ == 1
template<long long M>
struct modint {
private:
    using ll = long long;
    using mint = modint<M>;

    ll v;
public:
    static constexpr ll MOD = M;
    modint(ll v=0):v((v%MOD+MOD)%MOD){}
    ll val() const { return v; }

    mint operator-() const { return mint(-v);}
    mint& operator++() { v++; if (v == MOD) v = -1; return *this; }
    mint& operator--() { if (v == -1) v = MOD; v--; return *this; }
    mint operator++(int) { mint r = *this; ++*this; return r; }
    mint operator--(int) { mint r = *this; --*this; return r; }

    mint& operator+=(const mint a) { if ((v += a.v) >= MOD) v -= MOD; return *this; }
    mint& operator-=(const mint a) { if ((v += MOD-a.v) >= MOD) v -= MOD; return *this; }
    mint& operator*=(const mint a) { (v *= a.v) %= MOD; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}

    mint pow(ll t) const { if (t==0) return 1; mint a = pow(t>>1); a *= a; if (t&1) a *= *this; return a; }
    mint inv() const { return pow(MOD-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
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

struct UnionFind {
    template<typename T> using vec = std::vector<T>;
    template<typename K, typename V> using map = std::map<K, V>;
    vec<int> d;

    UnionFind(int n=0): d(n,-1) {}

    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) std::swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y);}

    int size(int x) { return -d[find(x)];}

    vec<vec<int>> groups() {
        int n = d.size();
        vec<int> leader_buf(n), group_size(n);
        for (int i = 0; i < n; i++) {
            leader_buf[i] = find(i);
            group_size[leader_buf[i]]++;
        }
        vec<vec<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const vec<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
};

void solve(long long N, std::vector<long long> f) {
    using mint = mint998244353;

    UnionFind uf(N);
    rep(N) uf.unite(i, f[i]-1);

    mint ans = mint(2).pow(uf.groups().size()) - 1;
    out(ans);
}

void solve() {
    long long N;
    scanf("%lld",&N);
    std::vector<long long> f(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&f[i]);
    }
    solve(N, std::move(f));
}
#else
void solve() {
}
#endif

int main() {
#if __MULTIRUN__
    rep(10) {
        solve();
        out("*****");
    }
#else
    solve();
#endif

    return 0;
}
