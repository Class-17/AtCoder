#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> grid(n);
    for (auto &row : grid)
        cin >> row;
    vector<int> row(n), col(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'o') {
                ++row[i];
                ++col[j];
            }
        }
    i64 res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 'o')
                res += (col[j] - 1) * (row[i] - 1);
    cout << res << '\n';
    return 0;
}