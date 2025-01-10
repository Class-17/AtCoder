#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n);
    std::vector<int> de(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        de[u]++, de[v]++;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        std::ranges::sort(g[i], {}, [&](int x) {return -de[x];});
        int cnt = 0, rem = 0;
        for (auto &j : g[i]) {
            cnt += 1;
            rem = std::max(rem, 1 + cnt * de[j]);
        }
        res = std::max(res, rem);
    }
    std::cout << n - res << '\n';
    return 0;
}