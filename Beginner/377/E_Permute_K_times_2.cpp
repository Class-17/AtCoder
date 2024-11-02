#include <bits/stdc++.h>
#include <atcoder/math>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, k;
    std::cin >> n >> k;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i];
    std::vector<int> vis(n + 1);
    std::vector<int> res(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        int j = i;
        std::vector<int> a;
        while (!vis[j]) {
            a.push_back(j);
            vis[j] = 1;
            j = p[j];
        };
        int shift = atcoder::pow_mod(2, k, a.size());
        for (int j = 0; j < a.size(); ++j)
            res[a[j]] = a[(j + shift) % a.size()];
    }
    for (int i = 1; i <= n; ++i)
        std::cout << res[i] << " \n"[i == n];
    return 0;
}