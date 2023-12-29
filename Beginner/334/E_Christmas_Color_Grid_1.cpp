#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;
constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

i64 quick_pow(i64 x, i64 n) {
    i64 res = 1;
    while (n) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid)
        cin >> row;
    vector color(n, vector<int>(m));
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '#' or color[i][j]) continue;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            color[i][j] = k + 1;
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (auto &[dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
                    if (grid[nr][nc] != '#' or color[nr][nc]) continue;
                    color[nr][nc] = color[r][c];
                    q.emplace(nr, nc);
                }
            }
            ++k;
        }
    }
    i64 a = 0, b = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') continue;
            set<int> st;
            for (auto &[dr, dc] : dirs) {
                int nr = i + dr, nc = j + dc;
                if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
                if (grid[nr][nc] == '.') continue;
                st.insert(color[nr][nc]);
            }
            a = (a + k - size(st) + 1) % MOD;
            b = (b + 1) % MOD;
        }
    cout << a * quick_pow(b, MOD - 2) % MOD;
    return 0;
}