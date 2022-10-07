#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> dirs{{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (auto &row : mat) cin >> row;
    auto solve = [&]()->pair<int, int> {
        int r = 0, c = 0;
        while (true) {
            if (mat[r][c] == '#') return {-1, -1};
            auto [dr, dc] = dirs[mat[r][c]];
            auto [nr, nc] = pair{r + dr, c + dc};
            if (nr < 0 or nr >= n or nc < 0 or nc >= m) return {r, c};
            mat[r][c] = '#';
            tie(r, c) = pair{nr, nc};
        }
        return {-1, -1};
    };
    auto [l, r] = solve();
    if (l == -1)
        cout << -1 << '\n';
    else
        cout << l + 1 << ' ' << r + 1 << '\n';
    return 0;
}