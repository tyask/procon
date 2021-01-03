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

struct Point {
    double x;
    double y;
};

const double th = M_PI * 60.0 / 180;

void koch(int n, Point p1, Point p2) {
    if (n == 0) {
        return;
    }

    Point s = dot(p1, p2, 1, 2);
    Point t = dot(p1, p2, 2, 1);
    Point u = {
        (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x,
        (t.x - s.x) * sin(th) - (t.y - s.y) * cos(th) + s.y
    };

    koch(n - 1, p1, s);
    koch(n - 1, s, u);
    koch(n - 1, u, t);
    koch(n - 1, t, p2);

}

Point dot(Point a, Point b, int m, int n) {
    return {
        (n * a.x + m * b.x) / (m + n),
        (n * a.y + m * b.y) / (m + n),
    };
}

int main() {
    int n;
    cin >> n;
}