#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<vector<int>> block(n);
    for (int i = 0; i < l; ++i) {
        int u, v;
        cin >> u >> v;
        block[u - 1].push_back(v - 1);
    }
    int res = 0;
    multiset<int> st;
    for (auto &x : b)
        st.insert(x);
    for (int i = 0; i < n; ++i) {
        for (auto &j : block[i])
            st.erase(st.find(b[j]));
        if (!st.empty())
            res = max(res, a[i] + *rbegin(st));
        for (auto &j : block[i])
            st.insert(b[j]);
    }
    cout << res << '\n';
    return 0;
}