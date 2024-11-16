#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<i64> q(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> q[i] >> r[i];
    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        i64 t, d;
        std::cin >> t >> d;
        if (d <= r[t]) std::cout << r[t] << '\n';
        else {
            i64 x = (d - r[t] + q[t] - 1) / q[t];
            std::cout << q[t] * x + r[t] << '\n';
        }
    }
    return 0;
}