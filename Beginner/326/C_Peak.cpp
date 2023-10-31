#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(begin(arr), end(arr));
    int res = 1;
    for (int i = 0, j = 0; j < n; ++i) {
        while (j < n and arr[j] - arr[i] < m) ++j;
        res = max(res, j - i);
    }
    cout << res << '\n';
    return 0;
}