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

vec<bool> dexCache(100000 + 1);
vec<bool> hexCache(100000 + 1);

bool includes7ByHex(int n) {
    bool ret = false;
    int d = pow(8, (int) (log(n) / log(8)));
    int a = n / d;
    if (a == 7) {
        ret = true;
    } else {
        ret = hexCache[n % d];
    }
    hexCache[n] = ret;
    return ret;

}

bool includes7ByDec(int n) {
    bool ret = false;
    int d = pow(10, (int) log10(n));
    int a = n / d;
    if (a == 7) {
        ret = true;
    } else {
        ret = dexCache[n % d];
    }
    dexCache[n] = ret;
    return ret;
}

int main() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        bool b = false;
        b |= includes7ByDec(i);
        b |= includes7ByHex(i);
        if (!b) {
            c++;
        }
    }
    p(c);
}
