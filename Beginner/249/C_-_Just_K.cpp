#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<string> arr(n);
    for (auto &s : arr) cin >> s;
    int res = 0;
    for (int i = (1 << n) - 1; i >= 0; --i) {
        vector<int> cnt(26);
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1 ^ 1) continue;
            for (auto &ch : arr[j]) ++cnt[ch - 'a'];
        }
        int curr = 0;
        for (auto &x : cnt) curr += (x == k);
        res = max(res, curr);
    }
    cout << res << '\n';
    return 0;
}