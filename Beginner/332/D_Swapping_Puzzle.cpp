#include <bits/stdc++.h>
using namespace std;

int count(vector<int> a) {
    int n = size(a), res = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ++res;
            }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector a(n, vector(m, 0)), b(n, vector(m, 0));
    for (auto &row : a)
        for (auto &x : row)
            cin >> x;
    for (auto &row : b)
        for (auto &x : row)
            cin >> x;
    vector<int> row(n), col(m);
    iota(begin(row), end(row), 0);
    iota(begin(col), end(col), 0);
    int res = 100;
    do {
        do {
            vector c(n, vector(m, 0));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    c[i][j] = a[row[i]][col[j]];
            if (c != b) continue;
            res = min(res, count(row) + count(col));
        } while (next_permutation(begin(col), end(col)));
    } while (next_permutation(begin(row), end(row)));
    cout << (res < 100 ? res : -1) << '\n';
    return 0;
}