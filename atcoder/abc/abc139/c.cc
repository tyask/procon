#include <bits/stdc++.h>
using namespace std;
using ll   = long long;
using ld   = long double;
using ull  = unsigned long long;
using uint = unsigned int;
template<typename T> using vec = vector<T>;

const ll LMAX  = numeric_limits<ll>::max();
const ll LMIN  = numeric_limits<ll>::min();
const int IMAX = numeric_limits<int>::max();
const int IMIN = numeric_limits<int>::min();

#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type, name, size) vec<type> name(size); in(name)

#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define each(i, c) for (auto&& i : (c))
#define itr(c) for (auto it = begin(c); it != end(c); ++it)

#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)

template<class T> void scan(T& a){ cin >> a; }
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }

template <typename T> void out(T&& t) { cout << t << endl; }

template <typename T, typename... Args> void out(T&& head, Args&&... args) {
    cout << head << " ";
    out(forward<Args>(args)...);
}

template <typename T, typename... Args> void debug(T&& head, Args&&... args) {
#ifdef __ONPC__
    out("[DEBUG]", forward<T>(head), forward<Args>(args)...);
#endif
}

template <typename Cont> ostream& write(ostream& os, const Cont& c) {
    itr(c) { os << ((it == c.begin()) ? "" : " ") << *it; }
    return os;
}

template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) { return write(os, c); }
template <typename T> ostream& operator<<(ostream& os, const list<T>& c) { return write(os, c); }

template <typename T, template<typename U, typename A=allocator<U>> class Cont> T sum(const Cont<T>& c) { return accumulate(all(c), 0LL); };
template <typename T, template<typename U, typename A=allocator<U>> class Cont> T max(const Cont<T>& c) { return *max_element(all(c)); };
template <typename T, template<typename U, typename A=allocator<U>> class Cont> T min(const Cont<T>& c) { return *min_element(all(c)); };

template <typename N> bool is_even(N n) { return n % 2 == 0; }
template <typename N> bool is_odd(N n) { return !is_even(n); }

void YES(bool b) { out(b? "YES" : "NO"); }
void Yes(bool b) { out(b? "Yes" : "No"); }
void yes(bool b) { out(b? "yes" : "no"); }

void solve() {
    INT(n);
    VEC(int, vh, n);
    int p = 0;
    int ans = 0;
    while (p < n) {
        int h = vh[p];
        int p2 = p + 1;
        while (p2 < n && vh[p2] <= h) {
            h = vh[p2];
            p2++;
        }

        int m = p2 - p - 1;
        p = p2;
        ans = max(ans, m);
    }
    out(ans);
}

int main() {
#ifdef __ONPC__
    rep(5) {
        solve();
        out("*****");
    }
#else
    solve();
#endif
    
}
