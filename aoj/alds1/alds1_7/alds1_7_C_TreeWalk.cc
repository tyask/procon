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

    void walk_preorder(vec<int>& ids) {
        ids.push_back(id);
        if (left != NIL)  ns[left].walk_preorder(ids);
        if (right != NIL) ns[right].walk_preorder(ids);
    }

    void walk_inorder(vec<int>& ids) {
        if (left != NIL)  ns[left].walk_inorder(ids);
        ids.push_back(id);
        if (right != NIL) ns[right].walk_inorder(ids);
    }

    void walk_postorder(vec<int>& ids) {
        if (left != NIL)  ns[left].walk_postorder(ids);
        if (right != NIL) ns[right].walk_postorder(ids);
        ids.push_back(id);
    }

};

Node* parent() {
    for (Node& n : ns) {
        if (n.parent == Node::NIL) {
            return &n;
        }
    }

    return nullptr;
}

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

    vec<int> preorder;
    vec<int> inorder;
    vec<int> postorder;
    Node& n = *parent();
    n.walk_preorder(preorder);
    n.walk_inorder(inorder);
    n.walk_postorder(postorder);

    p("Preorder");
    p("", preorder);
    p("Inorder");
    p("", inorder);
    p("Postorder");
    p("", postorder);


}