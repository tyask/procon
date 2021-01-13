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

#define __ATCODER__ 0

#if __ATCODER__ == 1
{% if prediction_success %}
void solve({{ formal_arguments }}) {
}
{% else %}
void solve() {
}
{% endif %}
#else
vec<int> w, v;
int n;
int W;

int rec(int i, int s) {
    if (i == n) return 0;
    if (s < w[i]) return rec(i+1, s);
    return max(rec(i+1, s), rec(i+1, s-w[i]) + v[i]);
}

int rec(vvec<int>& dp, int i, int s) {
    if (dp[i][s] >= 0) return dp[i][s];
    int res = 0;
    if (i == n) res = 0;
    else if (s < w[i]) res = rec(i+1, s);
    else res = max(rec(i+1, s), rec(i+1, s-w[i]) + v[i]);
    return dp[i][s] = res;
}

int roop() {
    vvec<int> dp(n, vec<int>(W+1, -1));
    for(int i = n - 1; i >= 0; --i) {
        for (int s = 0; s <= W; ++s) {
            if (s < w[i]) {
                dp[i][s] = dp[i+1][s];
            } else {
                dp[i][s] = max(dp[i+1][s], dp[i+1][s-w[i]] + v[i]);
            }
        }
    }
    return dp[0][W];
}

int roop2() {
    vvec<int> dp(n, vec<int>(W+1, -1));
    for(int i = 0; i < n; ++i) {
        for (int s = 0; s <= W; ++s) {
            if (s < w[i]) {
                dp[i][s] = dp[i+1][s];
            } else {
                dp[i][s] = max(dp[i+1][s], dp[i+1][s-w[i]] + v[i]);
            }
        }
    }
    return dp[0][W];
}

void solve() {
    n = 4;
    w = {2, 1, 3, 2};
    v = {3, 2, 4, 2};
    W = 5;
    out(rec(0, W));

    vvec<int> dp(n, vec<int>(W+1, -1));
    out(rec(dp, 0, W));
    out(roop());
}

#endif

int main() {
#if __ATCODER__ == 1
    {% if prediction_success %}
    {{input_part}}
    solve({{ actual_arguments }});
    {% else %}
    solve();
    {% endif %}
#elif __DEBUG__
    rep(1) {
        solve();
        out("*****");
    }
#else
    solve();
#endif

    return 0;
}
