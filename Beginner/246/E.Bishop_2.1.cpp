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
    vector<string> mat(n);
    for (auto &row : mat) cin >> row;
    vector<array<int, 4>> dist(n * n, {inf, inf, inf, inf});
    bitset<maxn * maxn * 4> memo;
    deque<tuple<int, int, int>> dq;
    for (int i = 0; i < 4; ++i) {
        dist[xs * n + ys][i] = 1;
        dq.emplace_back(xs, ys, i); 
    }
    while (!dq.empty()) {
        auto [r, c, d] = dq.front(); dq.pop_front();
        if (memo[(r * n + c) * 4 + d]) continue;
        memo[(r * n + c) * 4 + d] = true;
        for (int i = 0; i < 4; ++i) {
            auto &[dr, dc] = dirs[i];
            auto nr = r + dr, nc = c + dc;
            if (nr < 0 or nc < 0 or nr >= n or nc >= n) continue;
            if (mat[nr][nc] == '#') continue;
            int cost = dist[r * n + c][d] + (i != d);
            if (dist[nr * n + nc][i] < cost) continue;
            dist[nr * n + nc][i] = cost;
            if (i == d)
                dq.emplace_front(nr, nc, i);
            else
                dq.emplace_back(nr, nc, i);
        }
    }
    int res = *min_element(begin(dist[xe * n + ye]), end(dist[xe * n + ye]));
    cout << (res < inf ? res : -1) << '\n';
    return 0;
}