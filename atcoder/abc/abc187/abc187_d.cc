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

struct City {
    int a;
    int t;

    int sum() { return a + t; }
};

int main() {
    int n;
    vec<City> cs;
    cin >> n;
    REP(i, n) {
        City c;
        cin >> c.a >> c.t;
        cs.push_back(c);
    }

    sort(cs.begin(), cs.end(), [](auto& c1, auto& c2) {
        if (c1.sum() != c2.sum()) {
            return c1.sum() > c2.sum();
        } else if (c1.a != c2.a) {
            return c1.a > c2.a;
        } else {
            return c1.t > c2.t;
        }
    });

    for (int i = 0; i <= n; ++i) {
        ll a = 0;
        ll t = 0;
        for (int j = 0; j < n; ++j) {
            if (j < i) {
                t += cs[j].sum();
            } else {
                a += cs[j].a;
            }
        }

        if (a < t) {
            p(i);
            break;
        }
    }

}