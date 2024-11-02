#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i)
        for (int j = -1; j <= 1; ++j)
            ++cnt[(arr[i] + j + n - i) % n];
    cout << *max_element(begin(cnt), end(cnt)) << '\n';
    return 0;
}