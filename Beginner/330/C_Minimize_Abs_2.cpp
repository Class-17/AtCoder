#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n; cin >> n;
    i64 res = n;
    for (i64 i = 0; i * i <= n; ++i) {
        i64 j = sqrt(n - i * i);
        i64 x = abs(i * i + j * j - n);
        i64 y = abs(i * i + (j + 1) * (j + 1) - n);
        res = min({res, x, y});
    }
    cout << res << '\n';
    return 0;
}