#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    vector<i64> sum(q + 1), res(n + 1);
    for (int i = 1; i <= q; ++i) {
        int x; cin >> x;
        if (mp.contains(x)) {
            res[x] += sum[i-1] - sum[mp[x]-1];
            mp.erase(x);
            sum[i] += sum[i-1] + size(mp);
        }
        else {
            mp[x] = i;
            sum[i] += sum[i-1] + size(mp);
        }
    }
    for (auto &[k, v] : mp)
        res[k] += sum[q] - sum[v - 1];
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " \n"[i == n];
    return 0;
}