#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    std::ranges::sort(a);
    std::ranges::sort(b);
    i64 res = 0;
    for (int i = 0; i < n; ++i)
        res += std::abs(a[i] - b[i]);
    std::cout << res << '\n';
    return 0;
}