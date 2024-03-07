#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (auto &s : grid) cin >> s;
    int res = k + 1;
    for (int i = 0; i < n; ++i) {
        vector<int> sum(m);
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == '.')
                sum[j] = 1;
            else if (grid[i][j] == 'x')
                sum[j] = k + 1;
        partial_sum(begin(sum), end(sum), begin(sum));
        for (int j = k - 1; j < m; ++j) {
            int lo = j - k >= 0 ? sum[j - k] : 0;
            res = min(res, sum[j] - lo);
        }
    }
    for (int j = 0; j < m; ++j) {
        vector<int> sum(n);
        for (int i = 0; i < n; ++i)
            if (grid[i][j] == '.')
                sum[i] = 1;
            else if (grid[i][j] == 'x')
                sum[i] = k + 1;
        partial_sum(begin(sum), end(sum), begin(sum));
        for (int i = k - 1; i < n; ++i) {
            int lo = i - k >= 0 ? sum[i - k] : 0;
            res = min(res, sum[i] - lo);
        }
    }
    cout << (res <= k ? res : -1) << '\n';
    return 0;
}