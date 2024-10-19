#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 lowbit(i64 x) {
    return x & -x;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 a, b;
    cin >> a >> b;
    vector<pair<i64, i64>> res;
    while (a < b) {
        i64 c = (a > 0 ? lowbit(a) : (1LL << 60));
        while (b - a < c)
            c >>= 1;
        res.emplace_back(a, a + c);
        a += c;
    }
    cout << size(res) << '\n';
    for (auto &[x, y] : res)
        cout << x << ' ' << y << '\n';
    return 0;
}