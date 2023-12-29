#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    vector<double> dp(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int k = i; k > 0; --k)
            dp[k] = max(dp[k], dp[k - 1] * 0.9 + arr[i]);
    double res = -1200, w = 1;
    for (int i = 1; i <= n; ++i) {
        res = max(res, dp[i] / w - 1200 / sqrt(i));
        w = w * 0.9 + 1; 
    }
    cout << setprecision(15) << fixed << res << '\n';
    return 0;
}