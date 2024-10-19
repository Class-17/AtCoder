#include <bits/stdc++.h>
using namespace std;

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &s : grid) cin >> s;
    int res = 1;
    vector st(n, vector(m, 0));
    auto canMove = [&](int r, int c) {
        for (auto &[dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
            if (grid[nr][nc] == '#') return false;
        }
        return true;
    };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#' or st[i][j] or !canMove(i, j)) continue;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            st[i][j] = 1;
            int cur = 1;
            set<pair<int, int>> rel;
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                if (!canMove(r, c)) {
                    rel.emplace(r, c);
                    continue;
                }
                for (auto &[dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
                    if (grid[nr][nc] == '#' or st[nr][nc]) continue;
                    q.emplace(nr, nc);
                    st[nr][nc] = 1;
                    ++cur;
                }
            }
            for (auto &[r, c] : rel)
                st[r][c] = 0;
            res = max(res, cur);
        }
    cout << res << '\n';
    return 0;
}