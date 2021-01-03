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

int cnt = 0;
void merge(vec<int>& v, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vec<int> p1 = vec<int>(v.begin() + left, v.begin() + mid);
    vec<int> p2 = vec<int>(v.begin() + mid, v.begin() + right);
    p1.push_back(2000000000);
    p2.push_back(2000000000);

    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        if (p1[i] < p2[j]) {
            v[k] = p1[i];
            i++;
        } else {
            v[k] = p2[j];
            j++;
        }
    }
    cnt += right - left;
}

void mergeSort(vec<int>& v, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid, right);
        merge(v, left, mid, right);
    }
}

int main() {
    int n;
    vec<int> v;
    cin >> n >> vin(v, n);

    mergeSort(v, 0, n);
    p(v);
    p(cnt);
}