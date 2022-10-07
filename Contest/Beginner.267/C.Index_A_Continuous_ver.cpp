#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; 
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    ll curr = 0, sum = 0;
    for (int i = 0; i < m ; ++i) {
        curr += arr[n - m + i] * (i + 1);
        sum += arr[n - m + i];
    }
    ll res = curr;
    for (int i = n - 1 - m; i >= 0; --i) {
        sum += -arr[i + m] + arr[i];
        curr += -arr[i + m] * m + sum;
        res = max(res, curr);
    }
    cout << res << '\n';
    return 0;
}