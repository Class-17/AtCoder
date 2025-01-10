#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }
    std::vector<int> dfn(n, -1), low(n), ins(n), stk;
    int step = 0;
    std::vector<std::vector<int>> scc;
    auto dfs = [&](auto &self, int u)->void {
        dfn[u] = low[u] = step++;
        stk.push_back(u);
        ins[u] = 1;
        for (auto &v : g[u]) {
            if (dfn[v] == -1) {
                self(self, v);
                low[u] = std::min(low[u], low[v]);
            }
            else if (ins[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (low[u] < dfn[u]) return;
        std::vector<int> seq;
        while (true) {
            int v = stk.back(); stk.pop_back();
            seq.push_back(v);
            ins[v] = 0;
            if (v == u) break;
        }
        scc.push_back(seq);
    };
    for (int i = 0; i < n; ++i)
        if (dfn[i] == -1) dfs(dfs, i);
    i64 res = 0;
    for (auto &seq : scc)
        res += seq.size() * (seq.size() - 1LL) / 2;
    std::cout << res << '\n';
    return 0;
}