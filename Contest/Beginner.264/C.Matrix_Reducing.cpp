#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h1, w1;
    cin >> h1 >> w1;
    vector a(h1, vector<int>(w1));
    for (auto &x : a) for (auto &y : x) cin >> y;
    int h2, w2;
    cin >> h2 >> w2;
    vector b(h2, vector<int>(w2));
    for (auto &x : b) for (auto &y : x) cin >> y;
    auto check = [&]() {
        if (h1 < h2 or w1 < w2) return false;
        vector<vector<int>> rows, cols;
        for (int i = 0; i < (1 << h1); ++i) {
            if (__builtin_popcount(i) != h2) continue;
            vector<int> row;
            for (int j = 0; j < h1; ++j)
                if (i >> j & 1) row.push_back(j);
            rows.push_back(row);
        }
        for (int i = 0; i < (1 << w1); ++i) {
            if (__builtin_popcount(i) != w2) continue;
            vector<int> col;
            for (int j = 0; j < w1; ++j)
                if (i >> j & 1) col.push_back(j);
            cols.push_back(col);
        }
        auto comp = [&](int R, int C) {
            for (int i = 0; i < h2; ++i)
                for (int j = 0; j < w2; ++j)
                    if (b[i][j] != a[rows[R][i]][cols[C][j]]) return false;
            return true;
        };
        for (int i = 0; i < size(rows); ++i)
            for (int j = 0; j < size(cols); ++j)
                if (comp(i, j)) return true;
        return false;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}