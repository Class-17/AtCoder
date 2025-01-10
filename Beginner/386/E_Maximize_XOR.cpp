#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (auto &x : a) std::cin >> x;
    std::ranges::sort(a);
    a.erase(std::unique(a.begin(), a.end()), a.end());
    n = a.size();
    i64 res = 0, tot = std::accumulate(a.begin(), a.end(), 0LL, std::bit_xor{});
    auto dfs = [&](auto &self, int i, int cnt, i64 sum) {
        if (cnt == 0) {
            res = std::max(res, sum);
            return;
        }
        for (int j = i; j + cnt <= n; ++j)
            self(self, j + 1, cnt - 1, sum ^ a[j]);
    };
    if (k < n - k)
        dfs(dfs, 0, k, 0);
    else
        dfs(dfs, 0, n - k, tot);
    std::cout << res << '\n';
    return 0;
}