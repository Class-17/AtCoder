#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    reverse(begin(a) + l, end(a) + r + 1);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " \n"[i + 1 == n];
    return 0;
}