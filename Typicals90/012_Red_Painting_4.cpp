#include <bits/stdc++.h>
#include <atcoder/all>

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    int q; std::cin >> q;
    atcoder::dsu d(n * m);
    std::vector grid(n, std::vector(m, false));
    while (q--) {
        int t; std::cin >> t;
        if (t == 1) {
            int r, c;
            std::cin >> r >> c, --r, --c;
            grid[r][c] = 1;
            for (auto &[dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
                if (grid[nr][nc] == 0) continue;
                d.merge(r * m + c, nr * m + nc);
            }
        }
        else {
            int ra, ca, rb, cb;
            std::cin >> ra >> ca >> rb >> cb;
            --ra, --ca, --rb, --cb;
            if (grid[ra][ca] and d.same(ra * m + ca, rb * m + cb))
                std::cout << "Yes" << '\n';
            else
                std::cout << "No" << '\n';
        }
    }
    return 0;
}