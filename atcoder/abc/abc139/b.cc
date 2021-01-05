#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define EACH(x, c) for (auto& (x) : (c))

namespace common {
    void init_cin(const std::string& s) {
        cin.rdbuf((new istringstream(s))->rdbuf());
    }
}

namespace vec_utils {

template<typename T> using vec = vector<T>;

// Vin
template <typename T>
struct Vin {
    vec<T>& v;
    int count;
};

template <typename T> Vin<T> vin(vec<T>& v, int c) {
    return Vin<T>{v, c};
}

template <typename T> istream& operator>>(istream& is, Vin<T> v) {
    REP(i, v.count) {
        T t; is >> t;
        v.v.push_back(t);
    }
    return is;
}

// vrange
vec<int> vrange(int n) {
	vec<int> v(n);
	REP(i, n) v[i] = i;
	return v;
}

}

namespace print_utils {

template <typename T> void out(T&& t) {
    cout << t << endl;
}

template <typename T, typename... Args> void out(T&& head, Args&&... args) {
    cout << head << " ";
    p(forward<Args>(args)...);
}

template <typename Cont> ostream& write(ostream& os, const Cont& c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        os << ((it == c.begin()) ? "" : " ") << *it;
    }

    return os;
}

template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) {
    return write(os, c);
}

template <typename T> ostream& operator<<(ostream& os, const list<T>& c) {
    return write(os, c);
}

}


using namespace common;
using namespace vec_utils;
using namespace print_utils;

void solve(int a, int b) {
    int b1 = b - 1;
    int a1 = a - 1;
    int d = b1 / a1;
    out(d + (b1 % a1 == 0 ? 0 : 1));
}

void solve() {
    int a, b;
    cin >> a >> b;
    solve(a, b);
}

int main() {
    solve();
}