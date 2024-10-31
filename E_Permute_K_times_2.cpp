#include <bits/stdc++.h>

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
        do {
            a.push_back(p[j]);
            vis[j] = 1;
            j = p[j];
        } while (j != i);
        for (auto &x : a)
            std::cout << x << " ";
        std::cout << '\n';
        std::rotate(a.begin(), a.begin() + k % a.size(), a.end());
        for (auto &x : a)
            std::cout << x << " ";
        std::cout << '\n';
        j = i;
        for (auto &x : a) {
            res[j] = a[j];
            j = p[j];
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cout << res[i] << " \n"[i == n];
    return 0;
}