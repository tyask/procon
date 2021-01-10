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

vec<int> preorder;
vec<int> inorder;

int reconstruct(int idx, Node& parent, const vec<int>& inorderBlock) {
    if (inorderBlock.empty()) {
        return idx;
    }

    int id = preorder[idx];
    Node& n = ns[id - 1];
    n.id = id;
    n.parent = parent.id;
    if (inorderBlock.size() == 1) {
        return idx;
    }

    auto it = find(inorderBlock.begin(), inorderBlock.end(), id);
    vec<int> lb(inorderBlock.begin(), it);
    vec<int> rb((it == inorderBlock.end()) ? inorderBlock.end() : it + 1, inorderBlock.end());

    int next = idx;
    if (!lb.empty()) {
        ++next;
        n.left = preorder[next] - 1;
        next = reconstruct(next, n, lb);
    }

    if (!rb.empty()) {
        ++next;
        n.right = preorder[next] - 1;
        next = reconstruct(next, n, rb);
    }

    return next;
}

int main() {
    cin >> N;
    ns.resize(N);

    cin >> vin(preorder, N);
    cin >> vin(inorder, N);

    Node dum;
    reconstruct(0, dum, inorder);
    vec<int> postorder;
    parent()->walk_postorder(postorder);
    p(postorder);

}