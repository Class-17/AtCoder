#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n), mp(n);
    iota(begin(arr), end(arr), 0);
    iota(begin(mp), end(mp), 0);
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        int idx = mp[x - 1];
        if (idx == n - 1) --idx;
        swap(arr[idx], arr[idx + 1]);
        mp[arr[idx]] = idx;
        mp[arr[idx + 1]] = idx + 1;
    }
    for (int i = 0; i < n; ++i)
        cout << arr[i] + 1 << (i + 1 < n ? ' ' : '\n');
    return 0;
}