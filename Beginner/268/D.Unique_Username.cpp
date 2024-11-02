#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> strs(n);
    for (auto &s : strs) cin >> s;
    set<string> st;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        st.insert(s);
    }
    vector<int> p(n);
    iota(begin(p), end(p), 0);
    int tot = 0;
    for (auto &s : strs) tot += size(s);
    do {
        auto dfs = [&](auto &dfs, int idx, int rem, string s) {
            s += strs[p[idx]];
            if (size(s) > 16) return;
            if (idx == n - 1) {
                if (st.find(s) == st.end() and size(s) >= 3) {
                    cout << s << '\n';
                    exit(0);
                }
                return;
            }
            for (int i = 1; i <= rem; ++i) {
                s.push_back('_');
                dfs(dfs, idx + 1, rem - i, s);
            }
            return;
        };
        dfs(dfs, 0, 16 - tot, "");
    } while (next_permutation(begin(p), end(p)));
    cout << -1 << '\n';
    return 0;
}