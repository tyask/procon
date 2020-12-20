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

void func(const string& s) {
    stack<int> downs;
    stack<pair<int, int>> areas;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '\\') {
            downs.push(c);
        } else if (c == '/' && downs.size() > 0) {
            int j = downs.top();
            downs.pop();
            int a = i - j;
            sum += a;
            while (areas.size() > 0 && areas.top().first > j) {
                a += areas.top().second;
                areas.pop();
            }

            areas.push(make_pair(j, a));
        }
    }

}

int main() {
    // string s;
    // cin >> s;
    func(R"(\\///\_/\/\\\\/_/\\///__\\\_\\/_\/_/\)");
}