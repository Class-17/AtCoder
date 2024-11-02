#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> mat(n);
    for (auto &row : mat) cin >> row;
    ll res = 0;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c) {
            for (int dr = -1; dr <= 1; ++dr)
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 and dc == 0) continue;
                    ll curr = 0;
                    for (int i = 0; i < n; ++i) {
                        int rr = (r + dr * i + n) % n;
                        int cc = (c + dc * i + n) % n;
                        curr = curr * 10 + mat[rr][cc] - '0';
                    }
                    res = max(res, curr);
                }
        }
    cout << res << '\n';
    return 0;
}