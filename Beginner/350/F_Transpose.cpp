#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int cnt;
    vector<Node*> sub;

    Node() : ch('*'), cnt(1) {}

    Node(char ch) : ch(ch), cnt(0) {}

    char flip(char ch, int bit) {
        if (~bit & 1) return ch;
        return islower(ch) ? toupper(ch) : tolower(ch);
    }

    void print(int pre_cnt = 0) {
        if (this == nullptr) return;
        cnt += pre_cnt;
        if (sub.empty())
            cout << flip(ch, cnt);
        if (cnt & 1)
            reverse(begin(sub), end(sub));
        for (auto &t : sub)
            t->print(cnt);
        delete this;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    vector<Node*> st;
    for (auto &ch : s) {
        if (ch == '(') {
            st.push_back(nullptr);
        }
        else if (ch == ')') {
            Node *t = new Node;
            while (!st.empty() and st.back() != nullptr) {
                t->sub.push_back(st.back());
                st.pop_back();
            }
            reverse(begin(t->sub), end(t->sub));
            if (!st.empty())
                st.pop_back();
            if (!t->sub.empty())
                st.push_back(t);
        }
        else {
            st.push_back(new Node(ch));
        }
    }
    for (auto &t : st)
        t->print();
    return 0;
}