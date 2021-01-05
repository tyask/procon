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
    int n;
    cin >> n;
    int mx = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int c = 0;
        int x = i;
        while (x % 2 == 0) {
            x /= 2;
            c++;
        }
        if (mx <= c) {
            mx = c;
            ans = i;
        }
    }

    out(ans);
}

void solve2() {
    int n;
    cin >> n;
    int ans = 0;
    REP(i, 7) {
        if (1 << i <= n) {
            ans = 1 << i;
        }
    }

    out(ans);
}

int main() {
    REP(i, 5) {
        if (i != 0) {
            out("*****");
        }
        solve2();
    }
}
