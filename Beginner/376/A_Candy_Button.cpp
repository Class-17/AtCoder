#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, c;
    std::cin >> n >> c;
    int prev = -1000, res = 0;
    for (int i = 0; i < n; ++i) {
        int x; std::cin >> x;
        if (x - prev < c) continue;
        res += 1;
        prev = x;
    }
    std::cout << res << '\n';
    return 0;
}