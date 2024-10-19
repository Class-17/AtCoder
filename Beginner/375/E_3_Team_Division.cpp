#include <bits/stdc++.h>

void chmin(auto &x, const auto &y) {
    if (x > y) x = y;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i] >> b[i];
    int s[4]{0};
    for (int i = 0; i < n; ++i)
        s[a[i]] += b[i];
    s[0] = s[1] + s[2] + s[3];
    int t = s[0] / 3;
    std::vector dp(t + 1, std::vector(t + 1, n));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        std::vector ep(t + 1, std::vector(t + 1, n));
        for (int x = 0; x <= t; ++x)
            for (int y = 0; y <= t; ++y) {
                if (x + b[i] <= t)
                    chmin(ep[x + b[i]][y], dp[x][y] + (a[i] != 1));
                if (y + b[i] <= t)
                    chmin(ep[x][y + b[i]], dp[x][y] + (a[i] != 2));
                chmin(ep[x][y], dp[x][y] + (a[i] != 3));
            }
        dp = std::move(ep);
    }
    std::cout << (s[0] % 3 == 0 and dp[t][t] < n ? dp[t][t] : -1) << '\n';
    return 0;
}