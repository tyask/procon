#include <bits/stdc++.h>

namespace {
using namespace std;
using ll   = long long;
using ull  = unsigned long long;
using uint = unsigned int;
template<typename T> using vec = vector<T>;
template<typename T> using vvec = vec<vec<T>>;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll LINF=LLONG_MAX/3;
const int INF=INT_MAX/2-100;
const double DINF=numeric_limits<double>::infinity();
const double EPS=1e-9;
const double PI=3.1415926535897932;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

#define PB push_back
#define MP make_pair
#define FI first
#define SE second

#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define overload2(_1,_2,name,...) name

#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define LINE(...) string __VA_ARGS__;scan_line(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type, name, size) vec<type> name(size); in(name)
#define VV(type,name,h,w) vvec<type>name(h,vec<type>(w)); in(name)

#define rep1(n) for(int i=0;i<n;++i)
#define rep2(i,n) for(int i=0;i<n;++i)
#define rep3(i,a,b) for(int i=a;i<b;++i)
#define rep4(i,a,b,c) for(int i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)

#define rrep1(n) for(int i=(n)-1;i>=0;i--)
#define rrep2(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep3(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define rrep4(i,a,n,s) for(int i=a+(n-a-1)/s*s;i>=a;i-=s)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)

#define erep1(n) for(int i=0;i<=n;++i)
#define erep2(i,n) for(int i=0;i<=n;++i)
#define erep3(i,a,n) for(int i=a;i<=n;++i)
#define erep4(i,a,n,s) for(int i=a;i<=n;i+=s)
#define erep(...) overload4(__VA_ARGS__,erep4,erep3,erep2,erep1)(__VA_ARGS__)

#define each(i, c) for (auto&& i : (c))
#define itr(c) for (auto it = begin(c); it != end(c); ++it)

#define rng1(i) begin(i),end(i)
#define rng2(i,a) begin(i),begin(i)+a
#define rng3(i,a,b) begin(i)+a,begin(i)+b
#define rng(...) overload3(__VA_ARGS__,rng3,rng2,rng1)(__VA_ARGS__)

template<typename T> void scan(T& a){ cin >> a; }
template<typename T> void scan(vec<T>& a, int n){ a.resize(n); for(auto&& i : a) scan(i); }
template<typename T> void scan(vec<T>& a){ scan(a, a.size()); }
template<typename T> void scan(vvec<T>& a){ for(auto&& v : a) scan(v); }
void scan_line(string& s) { getline(cin, s); }
void in(){}
template<typename Head, typename... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }

template<typename T> void out(ostream& os, T&& t) { os << t << endl; }
template<typename T> void outh(ostream& os, T&& t) { os << t << " "; }
template<typename T, typename... Args> void out(ostream& os, T&& head, Args&&... tail) { outh(os, head); out(os, tail...); };
template<typename T, typename... Args> void out(T&& head, Args&&... tail) { out(cout, head, tail...); }

template<typename Cont> ostream& write(ostream& os, const Cont& c) {
    itr(c) { os << ((it == c.begin()) ? "" : " ") << *it; }
    return os;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& c) { return write(os, c); }
template<typename T> ostream& operator<<(ostream& os, const list<T>& c) { return write(os, c); }
template<typename T> ostream& operator<<(ostream& os, const set<T>& c) { return write(os, c); }
template<typename K, typename V> ostream& operator<<(ostream& os, const map<K, V>& c) { return write(os, c); }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << p.first << ':' << p.second; }

template<typename Cont> auto sum(const Cont& c) { return accumulate(rng(c), 0LL); };
template<typename Cont> auto max(const Cont& c) { return *max_element(rng(c)); };
template<typename Cont> auto min(const Cont& c) { return *min_element(rng(c)); };
template<typename Cont> auto sort(Cont& c) { sort(rng(c)); };
template<typename Cont> auto reverse(Cont& c) { reverse(rng(c)); };
template<typename Cont, typename Comp> auto sort(Cont& c, Comp comp) { sort(rng(c), comp); };
template<class T, class U> bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
template<typename T> vector<T> cumsum(const vec<T>& v) { vec<T> s(v.size()+1, 0); rep(v.size()) s[i+1] = s[i] + v[i]; return s; }
template<typename T> vector<T> uniq(const vec<T>& v) { set<T> s(rng(v)); return vec<T>(rng(s)); }
template<typename T> T pop(queue<T>& q) { T t = q.front(); q.pop(); return t; }
template<typename T> T pop(priority_queue<T>& q) { T t = q.top(); q.pop(); return t; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a / gcd(a, b) * b; }
ll powint(ll n, ll k){ ll ans = 1; while(k){ if(k & 1) ans *= n; n *= n; k >>= 1; } return ans; }

void YES(bool b=true) { out(b? "YES" : "NO"); }
void Yes(bool b=true) { out(b? "Yes" : "No"); }
void yes(bool b=true) { out(b? "yes" : "no"); }
void NO(bool b=true) { YES(!b); }
void No(bool b=true) { Yes(!b); }
void no(bool b=true) { yes(!b); }

}

#define __ATCODER__ 1

#if __ATCODER__ == 1
void solve() {
    INT(H, W, K);
    VEC(str, s, H);

    vvec<int> ans(H, vec<int>(W));
    int col = 1;
    rep(H) {
        if (s[i].find('#')!=str::npos) ans[i][0] = col++;
    }

    rep(H) {
        int c = ans[i][0];
        if (c==0) continue;
        bool f = 0;
        rep(j, W) {
            if (s[i][j]=='#') {
                if (f) c = col++;
                f = 1;
            }
            ans[i][j] = c;
        }
    }

    vec<int> p;
    rep(H) if (ans[i][0]>0) {p = ans[i]; break; }

    rep(H) {
        if (ans[i][0]==0) {
            ans[i] = p;
        } else {
            p = ans[i];
        }
    }

    rep(H) out(ans[i]);

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
