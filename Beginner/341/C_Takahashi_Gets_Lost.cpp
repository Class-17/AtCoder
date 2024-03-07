#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    string s; cin >> s;
    vector<string> mat(n);
    for (auto &row : mat) cin >> row;
    auto run = [&](int r, int c) {
        for (auto &d : s) {
            switch (d) {
                case 'L': c -= 1; break;
                case 'R': c += 1; break;
                case 'U': r -= 1; break;
                case 'D': r += 1; break;
            }
            if (r < 0 or r >= n or c < 0 or c >= m) return false;
            if (mat[r][c] != '.') return false;
        }
        return true;
    };
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] == '.')
                res += run(i, j);
    cout << res << '\n';
    return 0;
}