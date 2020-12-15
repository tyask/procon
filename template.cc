#include <bits/stdc++.h>
using namespace std;

namespace vinput {

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

}

namespace print {

template <typename T> void p(T&& t) {
    cout << t << endl;
}

template <typename T, typename... Args> void p(T&& head, Args&&... args) {
    cout << head << " ";
    out(forward<Args>(args)...);
}

template <typename Cont, typename = typename Cont::iterator>
ostream& operator<<(ostream& os, const Cont& c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        os << ((it == c.begin()) ? "" : " ") << *it;
    }

    return os;
}
}

using namespace vinput;
using namespace print;

int main() {
}