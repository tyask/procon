#include <bits/stdc++.h>
namespace {
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wsign-compare"

#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...)    name
#define overload2(_1,_2,name,...)       name

#define template1(t)       template<typename t>
#define template2(t, u)    template<typename t, typename u>
#define template3(t, u, v) template<typename t, typename u, typename v>
#define TEMPLATE(...)      overload3(__VA_ARGS__, template3, template2, template1)(__VA_ARGS__)

using namespace std;
using ll   = long long;
using ull  = unsigned long long;
using uint = unsigned int;
using ld   = long double;
using str  = string;
using pii  = pair<int, int>;
using pll  = pair<ll, ll>;
TEMPLATE(T) using vec   = vector<T>;
TEMPLATE(T) using vvec  = vec<vec<T>>;
TEMPLATE(T) using graph = vvec<T>;
TEMPLATE(T) using pq    = priority_queue<T>; // descending
TEMPLATE(T) using pqg   = priority_queue<T, vec<T>, greater<T>>; // ascending

TEMPLATE(N) static constexpr N inf = numeric_limits<N>::max() / 2;
const ld EPS = 1e-9;
const ld PI  = 3.1415926535897932;
const ld TAU = 2 * PI;
const int    dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int    dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

#define PB push_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second

#define INT(...)  int    __VA_ARGS__; input(__VA_ARGS__)
#define LL(...)   ll     __VA_ARGS__; input(__VA_ARGS__)
#define ULL(...)  ull    __VA_ARGS__; input(__VA_ARGS__)
#define STR(...)  string __VA_ARGS__; input(__VA_ARGS__)
#define LINE(...) string __VA_ARGS__; scan_line(__VA_ARGS__)
#define CHR(...)  char   __VA_ARGS__; input(__VA_ARGS__)
#define DBL(...)  double __VA_ARGS__; input(__VA_ARGS__)
#define VEC(type, name, size)  vec<type>  name(size); input(name)
#define vv(type, name, h, ...) vvec<type> name(h, vec<type>(__VA_ARGS__))
#define VV(type, name, h, w)   vv(type, name, h, w); input(name)

#define rep1(n)       for(ll i=0; i<n; ++i)
#define rep2(i,n)     for(ll i=0; i<n; ++i)
#define rep3(i,a,b)   for(ll i=a; i<b; ++i)
#define rep4(i,a,b,c) for(ll i=a; i<b; i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)

#define rrep1(n)       for(ll i=(n)-1; i>=0;   --i)
#define rrep2(i,n)     for(ll i=(n)-1; i>=0;   --i)
#define rrep3(i,a,n)   for(ll i=(n)-1; i>=(a); --i)
#define rrep4(i,a,n,s) for(ll i=a+(n-a-1)/s*s; i>=a; i-=s)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)

#define erep1(n)       for(ll i=0; i<=n; ++i)
#define erep2(i,n)     for(ll i=0; i<=n; ++i)
#define erep3(i,a,n)   for(ll i=a; i<=n; ++i)
#define erep4(i,a,n,s) for(ll i=a; i<=n; i+=s)
#define erep(...) overload4(__VA_ARGS__,erep4,erep3,erep2,erep1)(__VA_ARGS__)

#define each(i,c) for (auto&& i : (c))
#define itr(c)    for (auto it = begin(c); it != end(c); ++it)

#define rng1(i)     begin(i),   end(i)
#define rng2(i,a)   begin(i),   begin(i)+a
#define rng3(i,a,b) begin(i)+a, begin(i)+b
#define rng(...) overload3(__VA_ARGS__,rng3,rng2,rng1)(__VA_ARGS__)

TEMPLATE(T) void scan(T& a) { cin >> a; }
TEMPLATE(T) void scan(vec<T>& a, int n) { a.resize(n); for(auto&& i : a) scan(i); }
TEMPLATE(T) void scan(vec<T>& a) { scan(a, a.size()); }
TEMPLATE(T) void scan(vvec<T>& a) { for(auto&& v : a) scan(v); }
void scan_line(string& s) { getline(cin, s); }
void input() {}
TEMPLATE(Head, ...Tail) void input(Head& head, Tail&... tail) { scan(head); input(tail...); }

struct exitter { void exit() { ::exit(0); } };
TEMPLATE(T) void out(ostream& os, T&& t) { os << t << '\n'; }
TEMPLATE(T) void outh(ostream& os, T&& t) { os << t << " "; }
TEMPLATE(T, ...Args) void out(ostream& os, T&& head, Args&&... tail) { outh(os, head); out(os, tail...); };
TEMPLATE(T, ...Args) exitter out(T&& head, Args&&... tail) { out(cout, head, tail...); return exitter{}; }
const char* empty_or_space[] = {"", " "};
TEMPLATE(Cont) ostream& write(ostream& os, const Cont& c) { itr(c) os << empty_or_space[it!=c.begin()] << *it; return os; }

TEMPLATE(T)    ostream& operator<<(ostream& os, const vector<T>& c) { return write(os, c); }
TEMPLATE(T)    ostream& operator<<(ostream& os, const vvec<T>& c) { each(v, c) out(os, v); return os; }
TEMPLATE(T)    ostream& operator<<(ostream& os, const list<T>& c) { return write(os, c); }
TEMPLATE(T)    ostream& operator<<(ostream& os, const set<T>& c) { return write(os, c); }
TEMPLATE(K, V) ostream& operator<<(ostream& os, const map<K, V>& c) { return write(os, c); }
TEMPLATE(T, U) ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << p.first << ':' << p.second; }

TEMPLATE(Cont) auto sum(const Cont& c) { return sum(rng(c)); }
TEMPLATE(N)    auto sum(const initializer_list<N>& c) { return sum(rng(c)); }
TEMPLATE(It)   auto sum(It b, It e) { return accumulate(b, e, typename It::value_type(0)); }
TEMPLATE(Cont) auto sumproduct(const Cont& c) { return sumproduct(rng(c)); }
TEMPLATE(N)    auto sumproduct(const initializer_list<N>& c) { return sumproduct(rng(c)); }
TEMPLATE(It)   auto sumproduct(It b, It e) { typename It::value_type v = 1; for(It it=b;it!=e;++it) v*=*it; return v; }
TEMPLATE(Cont) auto max(const Cont& c) { return *max_element(rng(c)); }
TEMPLATE(Cont) auto min(const Cont& c) { return *min_element(rng(c)); }
TEMPLATE(Cont) auto& sort(Cont& c) { sort(rng(c)); return c; }
TEMPLATE(Cont, Comp) auto& sort(Cont& c, Comp comp) { sort(rng(c), comp); return c; }
TEMPLATE(Cont) auto& reverse(Cont& c) { reverse(rng(c)); return c; }
TEMPLATE(T)    auto& uniq(vec<T>& v) { set<T> s(rng(v)); return v = vec<T>(rng(s)); }
TEMPLATE(T, U) bool chmin(T& a, const U& b) { if(a > b){ a = b; return 1; } return 0; }
TEMPLATE(T, U) bool chmax(T& a, const U& b) { if(a < b){ a = b; return 1; } return 0; }
TEMPLATE(Cont) size_t sz(const Cont& c) { return c.size(); }
TEMPLATE(T)    void compress(vec<T>& v) { auto a = v; sort(uniq(a)); rep(sz(v)) v[i] = lower_bound(rng(a),v[i])-a.begin(); }
TEMPLATE(T, S)    T pop(queue<T, S>& q) { T t = q.front(); q.pop(); return t; }
TEMPLATE(T, S, C) T pop(priority_queue<T, S, C>& q) { T t = q.top(); q.pop(); return t; }
TEMPLATE(T, S)    T pop_front(deque<T, S>& q) { T t = q.front(); q.pop_front(); return t; }
TEMPLATE(T, S)    T pop_back(deque<T, S>& q) { T t = q.back(); q.pop_back(); return t; }

void decrements() {}
TEMPLATE(Cont) void decrements(Cont&& c) { rep(c.size()) c[i]--; }
TEMPLATE(T, ...Tail) void decrements(T&& head, Tail&&... tail) { decrements(head); decrements(forward<Tail>(tail)...); }
TEMPLATE(Cont) bool in(const Cont& c, ll i) { return 0 <= i && i < c.size(); }
TEMPLATE(Cont) bool in(const vec<Cont>& c, ll i, ll j) { return in(c, i) && in(c[i], j); }
TEMPLATE(Cont) vec<Cont> rot(const vec<Cont>& c) {
    ll h = c.size(), w = c[0].size();
    vec<Cont> a(w, Cont(h, c[0][0]));
    rep(i,h)rep(j,w) a[j][h-1-i]=c[i][j];
    return a;
}
TEMPLATE(N) graph<N> undigraph(const vec<N>& u, const vec<N>& v) { graph<N> g(sz(u)); rep(sz(u)) g[u[i]].PB(v[i]), g[v[i]].PB(u[i]); return g; }
TEMPLATE(N) graph<N> digraph(const vec<N>& u, const vec<N>& v) { graph<N> g(sz(u)); rep(sz(u)) g[u[i]].PB(v[i]); return g; }

TEMPLATE(N) N gcd(N a, N b)    { while(b){ N c = b; b = a % b; a = c; } return a; }
TEMPLATE(N) N lcm(N a, N b)    { if(!a || !b) return 0; return a / gcd(a, b) * b; }
TEMPLATE(N) N powint(N n, N k) { N ans = 1; while(k){ if(k & 1) ans *= n; n *= n; k >>= 1; } return ans; }
TEMPLATE(N) N floor(N a, N b)  { return a / b; }
TEMPLATE(N) N ceil(N a, N b)   { return (a + b - 1) / b; }
TEMPLATE(N) N mod(N n, N m)    { N r = n % m; return (r < 0) ? r + m : r; }
TEMPLATE(N) N powmod(N n, N k, N m) { N ans = 1; while(k){ if(k & 1) (ans*=n)%=m; n%=m; (n*=n)%=m; k>>=1; } return ans; }
TEMPLATE(N) size_t popcount(N n)    { return bitset<sizeof(N)*8>(n).count(); }
TEMPLATE(N) N sumae(N n, N a, N e) { return n * (a + e) / 2; }
TEMPLATE(N) N sumad(N n, N a, N d) { return n * (2 * a + (n - 1) * d) / 2; }
TEMPLATE(N) struct cumsum : vec<N> {
    cumsum(const vec<N>& v): vec<N>(sz(v)+1) { rep(sz(v)) ref(i+1)=ref(i)+v[i]; }
    N operator()(int l, int r) { return ref(r)-ref(l); }
    N operator()(int r) { return operator()(0, r); }
    N& ref(int i) { return (*this)[i]; }
};

TEMPLATE(N) struct cumsum2d : vvec<N> {
    cumsum2d(const vvec<N>& v): vvec<N>(sz(v)+1, vec<N>(sz(v[0])+1)) {
        rep(i,sz(v))rep(j,sz(v[i])) ref(i+1,j+1)=ref(i,j+1)+ref(i+1,j)-ref(i,j)+v[i][j];
    }
    N operator()(int i1, int i2, int j1, int j2) { return ref(i2,j2)-ref(i1,j2)-ref(i2,j1)+ref(i1,j1); }
    N operator()(int i, int j) { return operator()(0, i, 0, j); }
    N& ref(int i, int j) { return (*this)[i][j]; }
};

struct pt : complex<ld> {
    pt(ld x, ld y) : complex<ld>(x, y) {}
    pt(complex<ld> c) : complex<ld>(c) {}
    static pt vec(pt from, pt to) { return to - from; }
    ld x() const { return real(); }
    ld y() const { return imag(); }
    const complex<ld>& cpx() const { return *this; };

    ld norm() const { return sqrtl(x()*x()+y()*y()); }

    pt operator-(pt p) const { return cpx() - p; }
    pt operator+(pt p) const { return cpx() + p; }
    pt operator*(pt p) const { return cpx() * p; }
    pt operator/(pt p) const { return cpx() / p; }

    pt operator+(ld d) const { return cpx() + d; }
    pt operator-(ld d) const { return cpx() - d; }
    pt operator*(ld d) const { return cpx() * d; }
    pt operator/(ld d) const { return cpx() / d; }

    pt rot(ld th) const { return pt(cosl(th)*x()-sinl(th)*y(), sinl(th)*x()+cosl(th)*y()); } // 反時計周りに回転
};
ostream& operator<<(ostream& os, const pt& p) { return os << p.x() << " " << p.y(); }

ld deg(ld rad) { return rad*180/PI; }
ld rad(ld deg) { return deg*PI/180; }
struct setupio {
    setupio() {
        // ios_base::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setupio;

#define YESNO(y, n) exitter y(bool b=true) { return out(b?#y:#n); } exitter n(bool b=true) { return y(!b); }
YESNO(YES, NO)
YESNO(Yes, No)
YESNO(yes, no)
YESNO(POSSIBLE, IMPOSSIBLE)
YESNO(Possible, Impossible)
}

#define __AUTO_GENERATE__ 1
#if __AUTO_GENERATE__ == 1
struct fenwick_tree {
    fenwick_tree(ll n) : dat(n), n(n) {}

    // O(logN)
    void add(ll p, ll v) {
        assert(0<=p && p<n);
        p++;
        while (p<=n) dat[p-1]+=v, p+=lsb(p);
    }

    ll get(ll p) { return sum(p, p+1); }
    void set(ll p, ll v) { add(p, v-get(p)); }

    // sum of [l, r) O(logN)
    ll sum(ll l, ll r) { return sum(r)-sum(l); }

    // sum of [0, r) O(logN)
    ll sum(ll p) {
        assert(0<=p && p<n);
        ll ret = 0;
        while (p>0) ret+=dat[p-1], p-=lsb(p);
        return ret;
    }

    ll lower_bound(ll v) {
        if (v <= 0) return 0;
        ll x = 0;
        for (ll k = largest_power_of_2(n); k>0; k/=2) {
            if (x+k<=n&&dat[x+k-1]<v) v-=dat[x+k-1], x+=k;
        }
        return x;
    }

private:
    vec<ll> dat;
    ll n;
    ll lsb(ll n) { return n & -n; }
    ll largest_power_of_2(ll n) { ll r = 1; while (r*2<=n) r*=2; return r; }
};

void solve() {
    LL(K);
    vvec<ll> a(K);
    rep(i,K) {
        LL(n);
        a[i].resize(n);
        input(a[i]);
    }
    LL(Q);
    VEC(ll, b, Q);

    decrements(b);
    const ll D = powint<ll>(10, 9);
    const ll M = 21;

    vvec<ll> acs(K);
    vec<ll> acc(K);
    rep(i,K) {
        ll x = 0;
        vec<ll> ac(M);
        rrep(j,sz(a[i])) x+=sum(rng(ac,0,a[i][j])), ac[a[i][j]]++;
        acs[i] = ac;
        acc[i] = x;
    }

    vec<ll> cnt(M);
    ll ans = 0;
    rrep(Q) {
        ll bi=b[i];

        ll x = acc[bi];
        auto& ac = acs[bi];

        rep(m,M) if (ac[m]) x+=sum(rng(cnt,m))*ac[m];

        // update cnt
        rep(m,M) cnt[m]+=ac[m];

        ans+=x;
        ans%=D;
    }

    out(ans);
}
#else
void solve() {
}
#endif

int main() {
#if __TEST__
    rep(10) {
        solve();
        out("*****");
    }
#else
    solve();
#endif

    return 0;
}