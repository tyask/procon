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
template <template <typename T, typename A=allocator<T>> typename Cont, typename T>
struct Vin {
    Cont<T>& c;
    int count;
};

template <template <typename T, typename A=allocator<T>> typename Cont, typename T>
Vin<Cont, T> vin(Cont<T>& c, int cnt) {
    return Vin<Cont, T>{c, cnt};
}

template <template <typename T, typename A=allocator<T>> typename Cont, typename T>
istream& operator>>(istream& is, Vin<Cont, T> v) {
    for (int i = 0; i < v.count; ++i) {
        T t; is >> t;
        v.c.push_back(t);
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
    int n, q;
    vec<int> s, t;
    cin >> n >> vin(s, n);
    cin >> q >> vin(t, q);

    int c = 0;
    unordered_set<int> set(s.begin(), s.end());
    for (int i : t) {
        if (set.find(i) != set.end()) {
            c++;
        }
    }

    p(c);
}