#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define EACH(x, c) for (auto& (x) : (c))

namespace common {
    void init_cin(const std::string& s) {
        cin.rdbuf((new istringstream(s))->rdbuf());
    }

    template<typename N>
    N div_roundup(N x, N y) {
        // x / y を切り上げ
        return (x + y - 1) / y;
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
    v.v.resize(v.count);
    REP(i, v.count) {
        is >> v.v[i];
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

void solve() {
    vec<vec<int>> a(3, vec<int>(3));
    int n;
    vec<int> b;
    REP(i, 3) cin >> vin(a[i], 3);
    cin >> n >> vin(b, n);

    for(int x : b) {
        for (auto& al : a) {
            for(int& ai : al) {
                if (x == ai) {
                    ai = 0;
                }
            }
        }
    }

    bool ans = false;
    if (
        (a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0) ||
        (a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0) ||
        (a[2][0] == 0 && a[2][1] == 0 && a[2][2] == 0) ||
        (a[0][0] == 0 && a[1][0] == 0 && a[2][0] == 0) ||
        (a[0][1] == 0 && a[1][1] == 0 && a[2][1] == 0) ||
        (a[0][2] == 0 && a[1][2] == 0 && a[2][2] == 0) ||
        (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) ||
        (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0)
    ) {
        out("Yes");
    } else {
        out("No");
    }
}

int main() {
    REP(i, 5) {
        if (i != 0) {
            out("*****");
        }
        solve();
    }
}
