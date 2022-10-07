#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(begin(arr), end(arr));
    vector<int> cnt(w + 1);
    for (int a = 0; a < n and arr[a] <= w; ++a) {
        cnt[arr[a]] = 1;
        for (int b = a + 1; b < n and arr[a] + arr[b] <= w; ++b) {
            cnt[arr[a] + arr[b]] = 1;
            for (int c = b + 1; c < n and arr[a] + arr[b] + arr[c] <= w; ++c) {
                cnt[arr[a] + arr[b] + arr[c]] = 1;
            }
        }
    }
    cout << accumulate(begin(cnt), end(cnt), 0) << '\n';
    return 0;
}