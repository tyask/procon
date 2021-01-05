#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); ++i)

template <typename Cont> ostream& write(ostream& os, const Cont& c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        os << ((it == c.begin()) ? "" : " ") << *it;
    }

    return os;
}

template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) {
    return write(os, c);
}

struct BinaryCode {
    vector<string> decode(string message) {
        int s = message.size();
        vector<int> q(s);
        REP(i, s) {
            q[i] = message[i] - '0';
        }

        vector<int> p(s);
        p[0] = 0;
        string s1 = decode(p, q);
        cout << "--" << endl;
        vector<int> p2(s);
        p2[0] = 1;
        string s2 = decode(p2, q);
        return {s1, s2};
    }

    string decode(vector<int>& p, const vector<int>& q) {
        for (int i = 0; i < p.size() - 1; ++i) {
            int x = lookup(q, i) - lookup(p, i - 1) - lookup(p, i);
            if (x == 0 || x == 1) {
                // OK;
                p[i + 1] = x;
            } else {
                return "NONE";
            }
        }

        int s = q.size();
        if (q[s - 1] == p[s - 2] + p[s - 1]) {
            stringstream ss;
            for (int n : p) {
                ss << n;
            }
            return ss.str();
        } else {
            return "NONE";
        }

    }

    int lookup(const vector<int>& v, int i) {
        if (i < 0 || v.size() <= i) {
            return 0;
        }

        return v[i];
    }
};

int main() {
    BinaryCode c;
    cout << c.decode("123210122") << endl;
    cout << c.decode("11") << endl;
    cout << c.decode("22111") << endl;
}