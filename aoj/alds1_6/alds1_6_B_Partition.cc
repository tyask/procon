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

auto partition(vec<int>& v) -> decltype(v.begin()) {
    int x = v[v.size() - 1];
    int i = -1;
    REP(j, v.size() - 1) {
        if (v[j] <= x) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[v.size() - 1]);
    return v.begin() + (i + 1);
}

int main() {
    // init_cin("12\n13 19 9 5 12 8 7 4 21 2 6 11");
    int n;
    vec<int> v;
    cin >> n >> vin(v, n);

    // auto pos = partition(v.begin(), v.end(), [&](int x){ return x <= v[n - 1]; });
    auto pos = partition(v);
    for (auto it = v.begin(); it != pos; ++it) {
        cout << *it << " ";
    }
    cout << "[" << *pos << "] ";

    for (auto it = pos + 1; it != v.end(); ++it) {
        cout << *it;
        if (it != v.end() - 1) cout << " ";
    }

    cout << endl;

}