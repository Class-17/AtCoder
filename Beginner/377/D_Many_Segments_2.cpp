#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i)
        std::cin >> l[i] >> r[i];
    std::vector<int> d(m + 1, 1);
    for (int i = 0; i < n; ++i)
        d[r[i]] = std::max(d[r[i]], l[i] + 1);
    i64 res = 0;
    for (int i = 1; i <= m; ++i) {
        d[i] = std::max(d[i], d[i - 1]);
        res += i - d[i] + 1;
    }
    std::cout << res << '\n';
    return 0;
}