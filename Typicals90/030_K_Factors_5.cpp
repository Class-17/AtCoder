#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(n + 1);
    for (int i = 2; i <= n; ++i) if (!cnt[i])
        for (int j = i; j <= n; j += i)
            cnt[j] += 1;
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (cnt[i] >= k) res += 1;
    std::cout << res << '\n';
    return 0;
}