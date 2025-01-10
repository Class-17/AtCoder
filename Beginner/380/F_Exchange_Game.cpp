#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, l;
    std::cin >> n >> m >> l;
    int k = n + m + l;
    std::vector<int> p3(k + 1, 1);
    for (int i = 1; i <= k; ++i)
        p3[i] = p3[i - 1] * 3;
    std::vector<int> a(k);
    for (auto &x : a) std::cin >> x;
    std::vector cache(2, std::vector(p3[k], false));
    std::vector dp(2, std::vector(p3[k], false));
    auto dfs = [&](auto &dfs, int t, int state)->bool {
        if (cache[t][state]) return dp[t][state];
        cache[t][state] = true;
        for (int i = 0; i < k; ++i) {
            if (state / p3[i] % 3 != t) continue;
            int putState = state - p3[i] * t + p3[i] * 2;
            if (!dfs(dfs, t ^ 1, putState))
                return dp[t][state] = true;
            for (int j = 0; j < k; ++j) {
                if (a[j] >= a[i] or putState / p3[j] % 3 != 2) continue;
                int takeState = putState - p3[j] * 2 + p3[j] * t;
                if (!dfs(dfs, t ^ 1, takeState))
                    return dp[t][state] = true;
            }
        }
        return dp[t][state];
    };
    int mask = 0;
    for (int i = n; i < n + m; ++i)
        mask += p3[i] * 1;
    for (int i = n + m; i < n + m + l; ++i)
        mask += p3[i] * 2;
    std::cout << (dfs(dfs, 0, mask) ? "Takahashi" : "Aoki") << '\n';
    return 0;
}