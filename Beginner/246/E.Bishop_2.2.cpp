#include <bits/stdc++.h>
using namespace std;

constexpr int dirs[][2] = {1, 1, 1, -1, -1, 1, -1, -1};
constexpr int inf = 0x3f3f3f3f;
constexpr int maxn = 1500;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int xs, ys, xe, ye;
    cin >> xs >> ys >> xe >> ye;
    --xs, --ys, --xe, --ye;
    bitset<maxn * maxn> st;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j)
            st[i * n + j] = (s[j] == '#');
    }
    vector<vector<int>> dist(n, vector<int>(n, inf));
    queue<pair<int, int>> q;
    q.emplace(xs, ys);
    dist[xs][ys] = 0;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        st[r * n + c] = 1;
        for (auto &[dr, dc] : dirs) {
            auto nr = r + dr, nc = c + dc;
            while (nr >= 0 and nc >= 0 and nr < n and nc < n) {
                if (st[nr * n + nc]) break;
                if (dist[nr][nc] <= dist[r][c]) break;
                q.emplace(nr, nc);
                dist[nr][nc] = dist[r][c] + 1;
                nr += dr, nc += dc;
            }
        }
    }
    cout << (dist[xe][ye] < inf ? dist[xe][ye] : -1) << '\n';
    return 0;
}