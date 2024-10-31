#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::set<std::pair<int, int>> st;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        for (int dx = -2; dx <= 2; ++dx)
            for (int dy = -2; dy <= 2; ++dy) {
                if (abs(dx) + abs(dy) != 3) continue;
                int nx = x + dx, ny = y + dy;
                if (1 <= nx and nx <= n and 1 <= ny and ny <= n)
                    st.emplace(nx, ny);
            }
        st.emplace(x, y);
    }
    std::cout << i64(n) * n - st.size() << '\n';
    return 0;
}