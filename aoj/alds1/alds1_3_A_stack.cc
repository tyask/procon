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

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& c) {
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
    stack<int> stack;
    map<char, function<int(int, int)>> funcs = {
        {'+', [](auto a, auto b) { return a + b;}},
        {'-', [](auto a, auto b) { return a - b;}},
        {'*', [](auto a, auto b) { return a * b;}},
        {'/', [](auto a, auto b) { return a / b;}},
    };

    while(cin.peek() != '\n') {
        string s;
        cin >> s;
        p(s);
        char c = s[0];
        auto it = funcs.find(c);
        if (it != funcs.end()) {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            stack.push(it->second(a, b));
        } else {
            stack.push(stoi(s));
        }
    }

    p(stack.top());
}
