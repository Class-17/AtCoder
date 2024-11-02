#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    vector<pair<int, int>> op(n + 1);
    for (int i = 1; i <= n; ++i) {
        int t, y;
        cin >> t >> y;
        op[i] = {t, y};
        if (t == 1) arr[i] = y;
        else        arr[i] = arr[i - 1] + y;
    }
    vector<pair<int, ll>> diff(n);
    for (int i = 1; i <= n; ++i) {
        diff[i - 1] = {arr[i] - arr[i - 1], i};
        // cout << diff[i - 1].first << ' ';
    }
    sort(begin(diff), end(diff), [](const auto &a, const auto &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    vector<int> tag(n + 1);
    for (int i = 0; i < k and diff[i].first < 0; ++i) {
        tag[diff[i].second] = 1;
    }
    ll x = 0;
    for (int i = 1; i <= n; ++i) {
        if (tag[i]) continue;
        if (op[i].first == 1) {
            x = op[i].second;
        }
        else {
            x += op[i].second;
        }
    }
    cout << x << '\n';
    return 0;
}