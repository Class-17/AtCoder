#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 f(i64 x) {
    i64 res = 1;
    for (int i = 0; i < x; ++i)
        res = res * x;
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n; cin >> n;
    for (int i = 1; i <= 15; ++i) {
        if (f(i) == n) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}