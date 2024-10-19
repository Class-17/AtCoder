#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    vector<int> row(n), col(n), diag1(n * 2), diag2(n * 2);
    for (int i = 1; i <= t; ++i) {
        int x; cin >> x;
        x -= 1;
        int r = x / n, c = x % n;
        bool c1 = ++row[r] == n;
        bool c2 = ++col[c] == n;
        bool c3 = ++diag1[r - c + n] == n;
        bool c4 = ++diag2[r + c] == n;
        if (c1 or c2 or c3 or c4) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}