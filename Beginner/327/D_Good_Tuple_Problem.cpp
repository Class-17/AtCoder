#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<int> g[N+1];
    for (int i = 0; i < m; ++i) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<int> st(n + 1, -1);
    bool bipartite = true;
    auto dfs = [&](auto &dfs, int u, int w)->void {
        st[u] = w;
        for (auto &v : g[u]) {
            if (st[v] == -1)
                dfs(dfs, v, w ^ 1);
            else if (st[v] == st[u])
                bipartite = false;
        }
    };
    for (int i = 1; i <= n; ++i)
        if (st[i] == -1)
            dfs(dfs, i, 0);
    cout << (bipartite ? "Yes" : "No") << '\n';
    return 0;
}