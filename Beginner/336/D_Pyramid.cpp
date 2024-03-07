#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> pre(n), suf(n);
    pre[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > pre[i - 1])
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = arr[i];
    }
    suf[n - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] > suf[i + 1])
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = arr[i];
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = max(res, min(pre[i], suf[i]));
    cout << res << '\n';
    return 0;
}