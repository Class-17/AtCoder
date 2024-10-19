#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, a, x, y;
    cin >> n >> a >> x >> y;
    map<i64, double> mp;
    auto dfs = [&](auto &dfs, i64 v)->double {
        if (v == 0) return 0;
        if (mp.count(v)) return mp[v];
        double minv = dfs(dfs, v / a) + x;
        double z = 0.0;
        for (int i = 2; i <= 6; ++i)
            z += dfs(dfs, v / i);
        z = z / 5.0 + y * 6 / 5.0;
        minv = min(minv, z);
        return mp[v] = minv;
    };
    cout << setprecision(12) << fixed << dfs(dfs, n) << '\n';
    return 0;
}