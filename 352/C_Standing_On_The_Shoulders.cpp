#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (auto &[a, b] : arr)
        cin >> a >> b;
    sort(begin(arr), end(arr), [&](const auto &a, const auto &b) {
        return b.first + a.second < a.first + b.second;
    });
    i64 res = 0;
    for (auto &[a, b] : arr)
        res += a;
    res = res - arr.back().first + arr.back().second;
    cout << res << '\n';
    return 0;
}