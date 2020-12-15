#include <bits/stdc++.h>
using namespace std;

namespace common {
    void init_cin(const std::string& s) {
        cin.rdbuf((new istringstream(s))->rdbuf());
    }
}

namespace vec_utils {

// Vin
template <typename T>
struct Vin {
    vector<T>& v;
    int count;
};

template <typename T> Vin<T> vin(vector<T>& v, int c) {
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
vector<int> vrange(int n) {
	vector<int> v(n);
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

template <typename Cont, typename = typename Cont::iterator>
ostream& operator<<(ostream& os, const Cont& c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        os << ((it == c.begin()) ? "" : " ") << *it;
    }

    return os;
}
}

using namespace common;
using namespace vec_utils;
using namespace print_utils;

int main() {
    init_cin("3\n1 2 3");
    
    int n;
    vector<int> v;
    cin >> n >> vin(v, n);
    p(n, v);
}