#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; 
    cin >> n >> m;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    vector<ll> dp(m + 1, LLONG_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = min(i, m); j > 0; --j)
            dp[j] = max(dp[j], dp[j - 1] + arr[i] * j);
    cout << dp[m] << '\n';
    return 0;
}