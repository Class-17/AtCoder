#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    map<int, i64> mp;
    for (auto &x : arr)
        ++mp[x];
    i64 prev = 0;
    for (auto it = rbegin(mp); it != rend(mp); ++it) {
        auto &[v, c] = *it;
        i64 curr = v * c;
        c = prev;
        prev += curr;
    }
    for (int i = 0; i < n; ++i)
        cout << mp[arr[i]] << " \n"[i + 1 == n];
    return 0;
}