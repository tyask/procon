#include <bits/stdc++.h>

namespace {
using namespace std;
using ll   = long long;
using ld   = long double;
using ull  = unsigned long long;
using uint = unsigned int;
template<typename T> using vec = vector<T>;
template<typename T> using vvec = vec<vec<T>>;

const ll LMAX  = numeric_limits<ll>::max();
const ll LMIN  = numeric_limits<ll>::min();
const int IMAX = numeric_limits<int>::max();
const int IMIN = numeric_limits<int>::min();

#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define overload2(_1,_2,name,...) name

#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type, name, size) vec<type> name(size); in(name)
#define VV(type,name,h,w) vvec<type>name(h,vec<type>(w)); in(name)

#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define each(i, c) for (auto&& i : (c))
#define itr(c) for (auto it = begin(c); it != end(c); ++it)

#define rng1(i) begin(i),end(i)
#define rngll2(i,a) begin(i),begin(i)+a
#define rng3(i,a,b) begin(i)+a,begin(i)+b
#define rng(...) overload3(__VA_ARGS__,rng3,rng2,rng1)(__VA_ARGS__)

template<class T> void scan(T& a){ cin >> a; }
template<class T> void scan(vec<T>& a, int n){ a.resize(n); for(auto&& i : a) scan(i); }
template<class T> void scan(vec<T>& a){ scan(a, a.size()); }
template<class T> void scan(vvec<T>& a){ for(auto&& v : a) scan(v); }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void init_cin(const std::string& s) { cin.rdbuf((new istringstream(s))->rdbuf()); }

template <typename T> void out_impl(ostream& os, T&& t) { os << t << endl; }
template <typename T> void outh_impl(ostream& os, T&& t) { os << t << " "; }
template <typename T, typename... Args> void out_impl(ostream& os, T&& head, Args&&... tail) { outh_impl(os, head); out_impl(os, tail...); };

template <typename T, typename... Args> void out(T&& head, Args&&... tail) { out_impl(cout, head, tail...); }
template <typename T, typename... Args> void debug(T&& head, Args&&... tail) {
#ifdef __DEBUG__
    out_impl(cerr, "[DEBUG]", head, tail...);
#endif
}

template <typename Cont> ostream& write(ostream& os, const Cont& c) {
    itr(c) { os << ((it == c.begin()) ? "" : " ") << *it; }
    return os;
}

template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) { return write(os, c); }
template <typename T> ostream& operator<<(ostream& os, const list<T>& c) { return write(os, c); }

template <typename Cont> auto sum(const Cont& c) { return accumulate(rng(c), 0LL); };
template <typename Cont> auto max(const Cont& c) { return *max_element(rng(c)); };
template <typename Cont> auto min(const Cont& c) { return *min_element(rng(c)); };
template<class T, class U> bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }

template <typename N> bool is_even(N n) { return n % 2 == 0; }
template <typename N> bool is_odd(N n) { return !is_even(n); }

void YES(bool b=true) { out(b? "YES" : "NO"); }
void Yes(bool b=true) { out(b? "Yes" : "No"); }
void yes(bool b=true) { out(b? "yes" : "no"); }
void NO(bool b=true) { YES(!b); }
void No(bool b=true) { Yes(!b); }
void no(bool b=true) { yes(!b); }

}

#define __ATCODER__ 1

#if __ATCODER__ == 1
struct dijkstra {
    using ll = long long;
    struct edge{ ll to; ll cost; };
    template<typename T> using vec = vector<T>;
    const ll LINF = LLONG_MAX/3;

    int n;
    vec<vec<edge>> g;
    vec<ll> d;
    vec<ll> prev;

    dijkstra(int n) : n(n), g(n) {};

    dijkstra& add(ll from, edge e) {
        assert(0<=from && from<n && 0<=e.to && e.to<n);
        g.at(from).push_back(e);
        return *this;
    }

    void run(int s) {
        assert(0<=s && s<n);
        using P = pair<ll, int>; // cost, node
        priority_queue<P, vec<P>, greater<P>> que;
        d.resize(n, LINF);
        prev.resize(n, -1);
        d[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [cost, v] = que.top(); que.pop();
            if (d[v] < cost) continue;
            for (edge e : g[v]) {
                if (chmin(d[e.to], d[v] + e.cost)) {
                    que.emplace(d[e.to], e.to);
                    prev[e.to] = v;
                }
            }
        }
    }

    ll shortest_path(int t) {
        return d[t];
    }

    vector<int> restore_shortest_path(int t) {
        vector<int> path;
        for (; t != -1; t = prev[t]) path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }

};

void solve(long long N, long long M, std::vector<long long> u, std::vector<long long> v, long long S, long long T) {
    rep(M) u[i]--, v[i]--;
    S--, T--;
    vvec<ll> g(N);
    rep(M) g[u[i]].push_back(v[i]);

    queue<tuple<ll, ll, ll>> q;
    ll ans = -1;
    vec<ll> vis(N);
    q.emplace(S, 3, 1);
    vis[S] = 1;
    while(q.size()) {
        auto [v, k, c] = q.front(); q.pop();
        if (k == 0) {
            if (v == T) { ans = c; break; }
            if (vis[v]) continue;
            vis[v] = 1;
            each(n, g[v]) q.emplace(n, 2, c+1);
        } else {
            each(n, g[v]) q.emplace(n, k-1, c);
        }
    }

    out(ans);
}

void solve2(long long N, long long M, std::vector<long long> u, std::vector<long long> v, long long S, long long T) {
    rep(M) u[i]--, v[i]--;
    S--, T--;
    vvec<ll> g(N);
    rep(M) g[u[i]].push_back(v[i]);

    queue<tuple<ll, ll>> q;
    const ll LINF = 1001001001LL;
    vvec<ll> dist(N, vec<ll>(3, LINF));
    q.emplace(S, 0);
    dist[S][0] = 0;
    while(q.size()) {
        auto [v, c] = q.front(); q.pop();
        each(n, g[v]) {
            ll nc = (c+1) % 3;
            if (dist[n][nc]!=LINF) continue;
            dist[n][nc] = dist[v][c] + 1;
            q.emplace(n, nc);
        }
    }
    ll ans = dist[T][0];
    if (ans == LINF) ans = -1; else ans /= 3;
    out(ans);
}
#else
void solve() {
}
#endif

int main() {
#if __ATCODER__ == 1
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> u(M);
    std::vector<long long> v(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&u[i]);
        scanf("%lld",&v[i]);
    }
    long long S;
    scanf("%lld",&S);
    long long T;
    scanf("%lld",&T);
    solve2(N, M, std::move(u), std::move(v), S, T);
#elif __DEBUG__
    rep(10) {
        solve();
        out("*****");
    }
#else
    solve();
#endif

    return 0;
}
