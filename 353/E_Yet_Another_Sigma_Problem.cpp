#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Trie {
private:
    array<Trie*, 26> child;
    int tail;
    int f(const char &ch) {return ch - 'a';}
public:
    Trie() : tail(0) {child.fill(nullptr);};

    void insert(const string &s) {
        Trie *t = this;
        for (auto &ch : s) {
            int x = f(ch);
            if (!t->child[x])
                t->child[x] = new Trie;
            t->child[x]->tail += 1;
            t = t->child[x];
        }
    }

    i64 search(const string &s) {
        Trie *t = this;
        i64 res = 0;
        for (auto &ch : s) {
            int x = f(ch);
            if (!t->child[x]) return res;
            res += t->child[x]->tail;
            t = t->child[x];
        }
        return res;
    }

    void del() {
        for (auto &x : child)
            if (x) x->del();
        delete this;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    i64 res = 0;
    Trie t;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        res += t.search(s);
        t.insert(s);
    }
    cout << res << '\n';
    return 0;
}