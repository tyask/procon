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

void solve(vec<int>& v) {
    queue<int> evens;
    queue<int> odds;
    sort(v.begin(), v.end(), greater<int>());
    for (int n : v) {
        if (n % 2 == 0) {
            evens.push(n);
        } else {
            odds.push(n);
        }
    }

    ll a = 0, b = 0;
    bool t = true;
    while (!evens.empty() || !odds.empty()) {

        int e = (evens.size() > 0) ? evens.front() : 0;
        int o = (odds.size() > 0) ?  odds.front() : 0;
        if (t) {
            // Alice
            if (e > o) {
                a += e;
                evens.pop();
            } else {
                odds.pop();
            }
        } else {
            // Bob
            if (o > e) {
                b += o;
                odds.pop();
            } else {
                evens.pop();
            }
        }

        t = !t;

    }

    if (a == b) {
        p("Tie");
    } else if (a > b) {
        p("Alice");
    } else {
        p("Bob");
    }
}

int main() {
    int t;
    cin >> t;
    vec<vec<int>> cs(t);
    REP(i, t) {
        int n;
        cin >> n >> vin(cs[i], n);
    }

    for (auto& v : cs) {
        solve(v);
    }
}