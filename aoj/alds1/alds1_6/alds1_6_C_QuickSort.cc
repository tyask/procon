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

struct Card {
    string c;
    int n;
};

ostream& operator<<(ostream& os, const Card& c) {
    return os << c.c << " " << c.n;
}

int partition(vec<Card>& v, int p, int r) {
    Card x = v[r];
    int i = p - 1;
    for (int j = p; j < r - 1; ++j) {
        if (v[j].n <= x.n) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);
    return i + 1;
}

void quickSort(vec<Card>& cards, int p, int r) {
    if (p < r) {
        int q = partition(cards, p, r);
        quickSort(cards, p    , q - 1);
        quickSort(cards, q + 1, r);
    }
}

int main() {
    int n;
    vec<Card> cards;
    cin >> n;
    char x;
    // cin.ignore(1);
    cin >> x;
    REP(i, n) {
        Card c;
        cin >> c.c >> c.n;
        cards.push_back(c);
    }

    cout << "-----" << endl;
    quickSort(cards, 0, n);
    for (Card c : cards) {
        cout << c.c << " " << c.n << endl;
    }
}