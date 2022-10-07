#include <bits/stdc++.h>
using namespace std;

const string T = "atcoder";

constexpr int maxn = 7;

int bfs(string s) {
    queue<string> q;
    set<string> st;
    q.push(s);
    st.insert(s);
    int step = 0;
    while (!q.empty()) {
        int len = size(q);
        while (len--) {
            auto x = q.front(); q.pop();
            if (x == T) return step;
            for (int i = 0; i + 1 < maxn; ++i) {
                swap(x[i], x[i + 1]);
                if (st.find(x) == st.end()) {
                    q.push(x);
                    st.insert(x);
                }
                swap(x[i], x[i + 1]);
            }
        }
        ++step;
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    cout << bfs(s) << '\n';
    return 0;
}