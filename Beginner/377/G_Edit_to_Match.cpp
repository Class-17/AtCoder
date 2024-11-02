#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Trie {
private:
    std::array<Trie*, 26> child;
    int tail;
    int f(const char &ch) {return ch - 'a';}
public:
    Trie() : tail(1e9) {child.fill(nullptr);};

    void insert(const std::string &s) {
        Trie *t = this;
        std::vector<Trie*> st;
        for (auto &ch : s) {
            st.push_back(t);
            int x = f(ch);
            if (!t->child[x])
                t->child[x] = new Trie;
            t = t->child[x];
        }
        t->tail = 0;
        int cnt = 1;
        while (!st.empty()) {
            auto &v = st.back()->tail;
            v = std::min(v, cnt);
            st.pop_back();
            cnt += 1;
        }
    }

    int search(const std::string &s) {
        Trie *t = this;
        int n = s.size(), res = s.size();
        for (int i = 1; auto &ch : s) {
            int x = f(ch);
            if (!t->child[x]) return res;
            res = std::min(res, n - i + t->child[x]->tail);
            t = t->child[x];
            i += 1;
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
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    Trie t;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        std::cout << t.search(s) << '\n';
        t.insert(s);
    }
    return 0;
}