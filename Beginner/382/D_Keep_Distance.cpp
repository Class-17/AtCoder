#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> res;
    std::vector<int> a;
    auto dfs = [&](auto &dfs, int idx, int x) {
        if (idx == n) {
            res.push_back(a);
            return;
        }
        for (int i = x; i <= m - (n - idx - 1) * 10; ++i) {
            a.push_back(i);
            dfs(dfs, idx + 1, i + 10);
            a.pop_back();
        }
    };
    dfs(dfs, 0, 1);
    std::cout << res.size() << '\n';
    for (auto &seq : res)
        for (int i = 0; i < n; ++i)
            std::cout << seq[i] << " \n"[i + 1 == n];
    return 0;
}