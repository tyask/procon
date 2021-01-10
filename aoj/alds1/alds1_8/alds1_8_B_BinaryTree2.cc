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

struct Node {
    static constexpr int NIL = -1;
    int key = NIL;
    Node* parent;
    Node* left;
    Node* right;
    Node(int k): key(k) {}

    void walk_preorder(vec<int>& keys) {
        keys.push_back(key);
        if (left)  left->walk_preorder(keys);
        if (right) right->walk_preorder(keys);
    }

    void walk_inorder(vec<int>& keys) {
        if (left)  left->walk_inorder(keys);
        keys.push_back(key);
        if (right) right->walk_inorder(keys);
    }

    void walk_postorder(vec<int>& keys) {
        if (left)  left->walk_postorder(keys);
        if (right) right->walk_postorder(keys);
        keys.push_back(key);
    }
};

struct BinaryTree {
    Node* root = nullptr;

    void insert(int k) {
        Node* n = new Node(k);
        Node* p = nullptr;
        Node* x = root;
        while (x) {
            p = x;
            int xk = x->key;
            if (k == xk) {
                return;
            } else if (k < xk) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        n->parent = p;

        if (!p) {
            root = n;
        } else if (k < p->key) {
            p->left = n;
        } else {
            p->right = n;
        }
    }

    Node* find(int k) {
        Node* n = root;
        while (n) {
            int nk = n->key;
            if (k == nk) {
                return n;
            } else if (k < nk) {
                n = n->left;
            } else {
                n = n->right;
            }
        }

        return nullptr;
    }

    void print() {
        vec<int> in, pre;
        root->walk_inorder(in);
        root->walk_preorder(pre);
        p("", in);
        p("", pre);
    }
};

int main() {
    int n;
    cin >> n;
    BinaryTree t;
    REP(i, n) {
        string s;
        int x;
        cin >> s;
        if (s == "insert") {
            cin >> x;
            t.insert(x);
        } else if (s == "print") {
            t.print();
        } else if (s == "find") {
            cin >> x;
            p((t.find(x) ? "yes" : "no"));
        }
    }
}