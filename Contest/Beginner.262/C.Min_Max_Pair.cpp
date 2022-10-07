#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    ll cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (arr[i] == i) ++cnt;
    cnt = cnt * (cnt - 1) / 2;
    for (int i = 1; i <= n; ++i)
        if (arr[i] != i and arr[arr[i]] == i) {
            swap(arr[i], arr[arr[i]]);
            ++cnt;
        }
    cout << cnt << '\n';
    return 0;
}