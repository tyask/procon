#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)

namespace common {
    using ll = long long;

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

template <typename T> void p(T&& t) {
    cout << t << endl;
}

template <typename T, typename... Args> void p(T&& head, Args&&... args) {
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

vec<int> counting_sort(const vec<int>& a, int k) {
    p(a);
    vec<int> c(k);

    REP(i, a.size()) {
        c[a[i]]++;
    }
    p(c);
    for (int i = 1; i < c.size(); ++i) {
        c[i] += c[i-1];
    }
    p(c);
    vec<int> b(a.size());
    for (int i = a.size() - 1; i >= 0; --i) {
        p(a[i], c[a[i]]);
        b[c[a[i]] - 1] = a[i];
        c[a[i]]-=1;
    }

    return b;
}

int main() {
    // init_cin("7\n2 5 1 3 2 3 0");
    // init_cin("8\n4 5 0 3 1 5 0 5");
    int n;
    vec<int> v;
    cin >> n >> vin(v, n);
    vec<int> r = counting_sort(v, 10);
    p(r);
}