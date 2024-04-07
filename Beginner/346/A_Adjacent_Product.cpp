#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i + 1 < n; ++i)
        cout << a[i] * a[i + 1] << " \n"[i + 2 == n];
    return 0;
}