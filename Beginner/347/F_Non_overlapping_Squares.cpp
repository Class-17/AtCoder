#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using Mat = vector<vector<i64>>;

constexpr int D = 2;

void rotate(Mat &mat, int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            swap(mat[i][j], mat[j][i]);
    for (int i = 1; i <= n; ++i)
        reverse(begin(mat[i]) + 1, begin(mat[i]) + n + 1);
}

template<class T>
void chmax(T &x, const T &y) {
    if (x < y) x = y;
}

i64 calc(const Mat &mat, int n, int m) {
    Mat sum(n + D, vector<i64>(n + D));
    auto X = sum, Y = sum, Z = sum;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+mat[i][j];
    auto get = [&](int x1, int y1, int x2, int y2) {
        return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
    };
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i < m or j < m) continue;
            X[i][j] = get(i+1-m, j+1-m, i, j);
            chmax(X[i][j], max(X[i-1][j], X[i][j-1]));
        }
    for (int i = 1; i <= n; ++i)
        for (int j = n; j >= 1; --j) {
            if (i < m or j > n + 1 - m) continue;
            Y[i][j] = get(i+1-m, j, i, j-1+m);
            chmax(Y[i][j], max(Y[i-1][j], Y[i][j+1]));
        }
    for (int i = n; i >= 1; --i)
        for (int j = n; j >= 1; --j) {
            if (i > n + 1 - m or j > n + 1 - m) continue;
            Z[i][j] = get(i, j, i-1+m, j-1+m);
            chmax(Z[i][j], max(Z[i+1][j], Z[i][j+1]));
        }
    i64 res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i < m or i > n - m) continue;
            if (j < m or j > n - m) continue;
            chmax(res, X[i][j] + Y[i][j+1] + Z[i+1][1]);
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i <= m or i > n + 1 - m * 2) continue;
            if (j > n + 1 - m * 2) continue;
            const auto &v = get(i, j, i-1+m, j-1+m);
            chmax(res, X[i-1][n] + v + Z[i+m][1]);
        }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Mat grid(n + D, vector<i64>(n + D));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> grid[i][j];
    i64 res = 0;
    for (int i = 0; i < 4; ++i) {
        chmax(res, calc(grid, n, m));
        rotate(grid, n);
    }
    cout << res << '\n';
    return 0;
}