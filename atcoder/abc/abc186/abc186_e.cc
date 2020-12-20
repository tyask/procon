#include <bits/stdc++.h>
using namespace std;

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
    for (int i = 0; i < v.count; ++i) {
        T t; is >> t;
        v.v.push_back(t);
    }
    return is;
}

// vrange
vec<int> vrange(int n) {
	vec<int> v(n);
	for (int i = 0; i < n; ++i) v[i] = i;
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

int main() {
    int t;
    cin >> t;
    struct Case {
        int n;
        int s;
        int k;
    };

    vec<Case> v;
    for (int i = 0; i < t; ++i) {
        Case c;
        cin >> c.n >> c.s >> c.k;
        v.push_back(c);
    }

    for (Case c : v) {
        int cnt = 0;
        int pos = c.s;
        while (true) {
            cnt++;
            pos = (pos + c.k) % c.n;
            if (pos == 0) {
                p(cnt);
                break;
            } else if (pos == c.s) {
                p(-1);
                break;
            }
        }
    }
}