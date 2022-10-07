#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> out(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[v - 1].push_back(u - 1);
        ++out[u - 1];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (!out[i]) q.push(i);
    int cnt = n;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto &v : g[u])
            if (--out[v] == 0) q.push(v);
        --cnt;
    }
    cout << cnt << '\n';
    return 0;
}