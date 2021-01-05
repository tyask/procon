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
    int id;
    Node* parent;
    vec<Node*> children;

    int parent_id() {
        return parent ? parent->id : -1;
    }

    int depth() {
        if (!parent) {
            return 0;
        }

        return parent->depth() + 1;
    }

    const char* type() {
        if (!parent) {
            return "root";
        }

        if (children.empty()) {
            return "leaf";
        }

        return "internal node";
    }

    string child_ids() {
        stringstream ss;
        ss << '[';
        REP(i, children.size()) {
            Node* c = children[i];
            ss << (i == 0 ? "" : ", ") << c->id;
        }
        ss << ']';

        return ss.str();
    }
};

Node* lookup(Node* root, int id) {
    if (!root) {
        return nullptr;
    }

    if (root->id == id) {
        return root;
    }

    for (Node* ch : root->children) {
        Node* n = lookup(ch, id);
        if (n) {
            return n;
        }
    }

    return nullptr;
}

int main() {
    int n;
    cin >> n;
    vec<Node*> nodes(n);
    REP(i, n) {
        int id, k;
        cin >> id >> k;
        Node*& node = nodes[id];
        if (!node) {
            node = new Node{id, nullptr, {}};
        }

        node->children.resize(k);
        REP(j, k) {
            int cid;
            cin >> cid;
            Node*& c = nodes[cid];
            if (!c) {
                c = new Node{cid, nullptr, {}};
            }
            c->parent = node;
            node->children[j] = c;
        }
    }

    for (Node* node : nodes) {
        Node& nd = *node;
        cout << "node " << nd.id
             << ": parent = " << nd.parent_id()
             << ", depth = " << nd.depth()
             << ", " << nd.type()
             << ", " << nd.child_ids()
             << endl;
    }
}