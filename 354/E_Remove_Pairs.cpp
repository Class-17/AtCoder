#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j and (a[i] == a[j] or b[i] == b[j]))
                g[i].push_back(j);
    vector dp(n + 1, vector(1 << n, -1));
    auto dfs = [&](auto &dfs, int i, int mask)->int {
        if (dp[i][mask] != -1) return dp[i][mask];
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) continue;
            for (auto &j : g[i]) {
                if (mask >> j & 1) continue;
                if (!dfs(dfs, i + 1, mask | (1 << i) | (1 << j)))
                    return dp[i][mask] = 1;
            }
        }
        return dp[i][mask] = 0;
    };
    cout << (dfs(dfs, 0, 0) ? "Takahashi" : "Aoki") << '\n';
    return 0;
}