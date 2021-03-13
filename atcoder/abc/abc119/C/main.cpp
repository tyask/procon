#include <bits/stdc++.h>

namespace {
using namespace std;
using ll   = long long;
using ld   = long double;
using ull  = unsigned long long;
using uint = unsigned int;
template<typename T> using vec = vector<T>;
template<typename T> using vvec = vec<vec<T>>;

const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const ll dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

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
// ll pow(ll n, ll k){ ll ans = 1; while(k){ if(k & 1) ans *= n; a *= n; n >>= 1; } return ans; }
ll powmod(ll n, ll k, ll m){ ll ans = 1; while(k){ if(k & 1) (ans *= n) %= m; (n *= n) %= m; k >>= 1; } return ans; }
ll mod(ll n, ll m) { ll r = n % m; return (r < 0) ? r + m : r; }

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
ll A, B, C, N;
vec<ll> l;
int ans = INF;
void dfs(int idx, int a, int b, int c, int mp) {
    if (idx == l.size()) {
        if (a==0||b==0||c==0) return;
        chmin(ans, abs(A-a)+abs(B-b)+abs(C-c)+mp - 30);
        return;
    }

    dfs(idx+1, a, b, c, mp);
    dfs(idx+1, a+l[idx], b, c, mp+10);
    dfs(idx+1, a, b+l[idx], c, mp+10);
    dfs(idx+1, a, b, c+l[idx], mp+10);
}

void dfs2(int depth, vec<int> v) {
    if (depth == N) {
        vec<int> b(3);
        int mp = 0;
        rep(N) {
            if (v[i]>0) {
                b[v[i]-1] += l[i];
                mp += 10;
            }
        }
        if (count(rng(b), 0)>0) {
            return;
        }

        chmin(ans, abs(b[0]-A)+abs(b[1]-B)+abs(b[2]-C)+mp-30);
        return;
    }

    rep(4) {
        v[depth] = i;
        dfs2(depth+1, v);
    }
}

void solve(long long N, long long A, long long B, long long C, std::vector<long long> l) {
    ::N = N, ::A = A, ::B = B, ::C = C, ::l = l;
    // dfs(0, 0, 0, 0, 0);
    dfs2(0, vec<int>(N));
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
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    std::vector<long long> l(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&l[i]);
    }
    solve(N, A, B, C, std::move(l));
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
