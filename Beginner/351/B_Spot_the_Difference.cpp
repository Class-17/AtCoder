#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> a(n), b(n);
    for (auto &row : a) cin >> row;
    for (auto &row : b) cin >> row;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] != b[i][j]) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
    return 0;
}