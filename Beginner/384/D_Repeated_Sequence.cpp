#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, t;
    std::cin >> n >> t;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i) 
        a.push_back(a[i]);
    std::partial_sum(a.begin(), a.end(), a.begin());
    const auto &[d, r] = std::div(t, a[n]);
    for (int i = 1; i <= n; ++i) {
        auto p = std::lower_bound(a.begin() + i - 1, a.begin() + i + n, a[i - 1] + r) - a.begin();
        if (p < i + n and a[p] == a[i - 1] + r) {
            std::cout << "Yes" << '\n';
            return 0;
        }
    }
    std::cout << "No" << '\n';
    return 0;
}