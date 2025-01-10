#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += std::abs(a[i] - b[i]);
    std::cout << (k >= res and (k - res) % 2 == 0 ? "Yes" : "No") << '\n';
    return 0;
}