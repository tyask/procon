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

struct Node;

int N;
vec<Node> ns;

struct Node {
    static constexpr int NIL = -1;
    int id     = NIL;
    int parent = NIL;
    int left   = NIL;
    int right  = NIL;

    int sibling() {
        if (parent == NIL) {
            return NIL;
        }

        Node& p = ns[parent];
        return (id == p.left) ? p.right : p.left;
    }

    int deg() {
        int c = 0;
        if (left != NIL) {
            c++;
        }
        if (right != NIL) {
            c++;
        }

        return c;
    }

    int depth() {
        return (parent == NIL) ? 0 : ns[parent].depth() + 1;
    }

    int height() {
        int lh = (left == NIL)  ? -1 : ns[left].height();
        int rh = (right == NIL) ? -1 : ns[right].height();
        return max(lh, rh) + 1;
    }

    const char* type() {
        if (parent == NIL) {
            return "root";
        }

        if (left == NIL && right == NIL) {
            return "leaf";
        }

        return "internal node";
    }
};

int main() {
    cin >> N;
    ns.resize(N);

    REP(i, N) {
        int id, l, r;
        cin >> id >> l >> r;
        Node& n = ns[id];
        n.id = id;
        n.left = l;
        n.right = r;
        if (l >= 0)
            ns[l].parent = id;
        if (r >= 0)
            ns[r].parent = id;
    }

    for (Node& n : ns) {
        cout << "node " << n.id << ":"
             << " parent = "   << n.parent
             << ", sibling = " << n.sibling()
             << ", degree = "  << n.deg()
             << ", depth = "   << n.depth()
             << ", height = "  << n.height()
             << ", " << n.type()
             << endl;
    }
}