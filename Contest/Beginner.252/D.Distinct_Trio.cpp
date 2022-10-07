#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<ll> cnt(*max_element(begin(arr), end(arr)) + 1);
    for (auto &x : arr) ++cnt[x];
    partial_sum(begin(cnt), end(cnt), begin(cnt));
    ll tot = 0;
    for (auto &x : arr)
        tot += cnt[x - 1] * (cnt.back() - cnt[x]);
    cout << tot << '\n';
    return 0;
}