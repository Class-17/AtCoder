#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> arr(k + 1);
    for (int i = 1; i <= k; ++i)
        cin >> arr[i];
    int res = 0;
    for (int i = 2; i <= k; i += 2)
        res += arr[i] - arr[i-1];
    if (k & 1 and k > 1) {
        vector<int> pre(k + 1), suf(k + 2);
        for (int i = 2; i <= k; i += 2)
            pre[i] = arr[i] - arr[i-1] + pre[i-2];
        for (int i = k - 1; i >= 0; i -= 2)
            suf[i] = arr[i+1] - arr[i] + suf[i+2];
        for (int i = 1; i <= k; i += 2)
            res = min(res, pre[i-1] + suf[i+1]);
    }
    cout << res << '\n';
    return 0;
}