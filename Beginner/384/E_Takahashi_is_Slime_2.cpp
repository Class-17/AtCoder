#include <bits/stdc++.h>

using i64 = long long;

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

struct Slime {
    int r, c;
    i64 w;
    bool operator < (const Slime &other) const {
        return w > other.w;
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, x;
    std::cin >> n >> m >> x;
    int r0, c0;
    std::cin >> r0 >> c0, --r0, --c0;
    std::vector grid(n, std::vector(m, 0uLL));
    for (auto &row : grid) for (auto &elem : row)
        std::cin >> elem;
    std::vector st(n, std::vector<bool>(m));
    i64 res = grid[r0][c0];
    grid[r0][c0] = 0;
    std::priority_queue<Slime> pq;
    pq.emplace(r0, c0, 0);
    while (!pq.empty() and pq.top().w * __int128_t(x) < res) {
        auto [r, c, w] = pq.top(); pq.pop();
        res += w;
        for (auto &[dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
            if (grid[nr][nc] == 0) continue;
            pq.emplace(nr, nc, grid[nr][nc]);
            grid[nr][nc] = 0;
        }
    }
    std::cout << res << '\n';
    return 0;
}