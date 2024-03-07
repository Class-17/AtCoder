#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<i64> arr(n);
    for (auto &x : arr) cin >> x;
    for (int i = 0; i + 1 < n; ++i) {
        i64 s, t;
        cin >> s >> t;
        arr[i + 1] += arr[i] / s * t;
    }
    cout << arr[n - 1] << '\n';
    return 0;
}