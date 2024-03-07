#include <bits/stdc++.h>
using namespace std;

constexpr int N = 45;

int grid[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int l = 0, r = n - 1, t = 0, b = n - 1, cnt = 0;
    while (cnt < n * n) {
        for (int i = l; i <= r; ++i)
            grid[t][i] = ++cnt;
        ++t;
        for (int i = t; i <= b; ++i)
            grid[i][r] = ++cnt;
        --r;
        for (int i = r; i >= l; --i)
            grid[b][i] = ++cnt;
        --b;
        for (int i = b; i >= t; --i)
            grid[i][l] = ++cnt;
        ++l;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i == n / 2 and j == n / 2)
                cout << "T" << ' ';
            else
                cout << grid[i][j] << " \n"[j + 1 == n];
    return 0;
}