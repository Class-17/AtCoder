#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 3;

i64 grid[N][N], st[N][N];

int check(int x) {
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j)
            if (st[i][j] == x) ++cnt;
        if (cnt == 3) return true;
    }
    for (int j = 0; j < N; ++j) {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
            if (st[i][j] == x) ++cnt;
        if (cnt == 3) return true;
    }
    int c1 = 0;
    for (int i = 0; i < N; ++i)
        if (st[i][i] == x) ++c1;
    if (c1 == 3) return true;
    int c2 = 0;
    for (int i = 0; i < N; ++i)
        if (st[i][N - 1 - i] == x) ++c2;
    if (c2 == 3) return true;
    return false;
}

int dfs(int i, i64 a, i64 b) {
    if (check(1)) return i % 2 == 0;
    if (check(2)) return i % 2 == 1;
    if (i == N * N) return a < b;
    bool win = false;
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            if (st[r][c] == 0) {
                if (i % 2 == 0) {
                    st[r][c] = 1;
                    win |= !dfs(i + 1, a + grid[r][c], b);
                }
                else { 
                    st[r][c] = 2;
                    win |= !dfs(i + 1, a, b + grid[r][c]);
                }
                st[r][c] = 0;
            }
    return win;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];
    cout << (dfs(0, 0, 0) ? "Takahashi" : "Aoki") << '\n';
    return 0;
}