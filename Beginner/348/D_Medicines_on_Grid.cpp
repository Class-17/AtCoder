#include <bits/stdc++.h>
using namespace std;

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

pair<int, int> find(vector<string> &grid, char x) {
    int n = size(grid), m = size(grid[0]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == x) return {i, j};
    return {-1, -1};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid)
        cin >> row;
    int k; cin >> k;
    vector<int> x(k + 1), y(k + 1), e(k + 1);
    vector mp(n, vector<int>(m, -1));
    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i] >> e[i];
        --x[i], --y[i];
        mp[x[i]][y[i]] = i;
    }
    tie(x[k], y[k]) = find(grid, 'T');
    mp[x[k]][y[k]] = k;
    auto [sx, sy] = find(grid, 'S');
    auto bfs = [&](int i) {
        vector<int> adj;
        queue<pair<int, int>> q;
        vector st(n, vector(m, 0));
        q.emplace(x[i], y[i]);
        st[x[i]][y[i]] = 1;
        while (!q.empty() and e[i]--) {
            int len = size(q);
            while (len--) {
                auto [x, y] = q.front(); q.pop();
                for (auto &[dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                    if (grid[nx][ny] == '#' or st[nx][ny]) continue;
                    q.emplace(nx, ny);
                    st[nx][ny] = 1;
                    if (mp[nx][ny] != -1)
                        adj.push_back(mp[nx][ny]);
                }
            }
        }
        return adj;
    };
    queue<int> q;
    vector<int> st(k + 1);
    for (int i = 0; i < k; ++i) 
        if (x[i] == sx and y[i] == sy) {
            q.push(i);
            st[i] = 1;
            break;
        }
    while (!q.empty()) {
        auto i = q.front(); q.pop();
        for (const auto &j : bfs(i)) {
            if (st[j]) continue;
            q.push(j);
            st[j] = 1;
        }
    }
    cout << (st[k] ? "Yes" : "No") << '\n';
    return 0;
}