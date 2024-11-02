#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> mat(n);
    for (auto &row : mat) cin >> row;
    auto check = [&]() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                char a = mat[i][j], b = mat[j][i];
                if (a == 'W' and b != 'L') return false;
                if (a == 'L' and b != 'W') return false;
                if (a == 'D' and b != 'D') return false;
            }
        return true;
    };
    cout << (check() ? "correct" : "incorrect") << '\n';
    return 0;
}