#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (auto &row : mat) cin >> row;
    auto find = [&]()->pair<int, int> {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j] == 'o') {
                    mat[i][j] = '-';
                    return {i, j};
                }
        return {0, 0};
    };
    auto [ax, ay] = find();
    auto [bx, by] = find();
    cout << abs(ax - bx) + abs(ay - by) << '\n';
    return 0;
}