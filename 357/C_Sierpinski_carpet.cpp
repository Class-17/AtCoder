#include <bits/stdc++.h>
using namespace std;

int f(int k) {
    return int(pow(3, k));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k; cin >> k;
    vector<string> mat(f(k), string(f(k), '.'));
    auto dfs = [&](auto &dfs, int k, int r, int c)->void {
        if (k == 0) {
            mat[r][c] = '#';
            return;
        }
        int len = f(k - 1);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                if (i == 1 and j == 1) continue;
                dfs(dfs, k - 1, r + i * len, c + j * len);
            }
    };
    dfs(dfs, k, 0, 0);
    for (auto &row : mat)
        cout << row << '\n';
    return 0;
}