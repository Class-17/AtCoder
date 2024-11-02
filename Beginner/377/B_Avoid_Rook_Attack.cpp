#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int N = 8;

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::vector<std::string> grid(N);
    for (auto &s : grid) std::cin >> s;
    int st[N][N] = {};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == '.') continue;
            for (auto &[dr, dc] : dirs) {
                int r = i, c = j;
                while (0 <= r and r < N and 0 <= c and c < N) {
                    st[r][c] = 1;
                    r += dr;
                    c += dc;
                }
            }
        }
    int res = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (st[i][j] == 0) res += 1;
    std::cout << res << '\n';
    return 0;
}