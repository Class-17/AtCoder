#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 60;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 a, b, c;
    cin >> a >> b >> c;
    int tot = __popcount(c);
    int minv = min(a, b), maxv = max(a, b);
    if (tot > maxv+minv or maxv-tot > minv or (maxv+minv-tot) % 2) {
        cout << -1 << '\n';
        return 0;
    }
    int com = (maxv + minv - tot) >> 1;
    i64 x = 0, y = 0;
    for (int i = 0; i < N and maxv > com; ++i)
        if (c >> i & 1) {
            x |= 1LL << i;
            --maxv;
        }
    y = c ^ x;
    for (int i = 0; i < N and com > 0; ++i)
        if (~c >> i & 1) {
            x |= 1LL << i;
            y |= 1LL << i;
            --com;
        }
    if (com > 0) {
        cout << -1 << '\n';
        return 0;
    }
    if (a < b) swap(x, y);
    cout << x << ' ' << y << '\n';
    return 0;
}