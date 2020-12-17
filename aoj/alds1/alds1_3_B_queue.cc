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

template <typename T> ostream& operator<<(ostream& os, const vec<T>& c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        os << ((it == c.begin()) ? "" : " ") << *it;
    }

    return os;
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

}

using namespace common;
using namespace vec_utils;
using namespace print_utils;

int main() {
    struct Process {
        string name;
        int time;
    };

    int n, q;
    cin >> n >> q;
    queue<Process> queue;
    for (int i = 0; i < n; ++i) {
        Process p;
        cin >> p.name >> p.time;
        queue.push(p);
    }

    int t = 0;
    vec<Process> ret;
    while (!queue.empty()) {
        Process p = queue.front();
        queue.pop();
        t += min(p.time, q);
        p.time -= q;
        if (p.time > 0) {
            queue.push(p);
        } else {
            ret.push_back({p.name, t});
        }
    }

    for (auto& r : ret) {
        p(r.name, r.time);
    }
    
}