#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int same = 0, diff = 0;
    for (int i = 0; i < n; ++i)
        same += (a[i] == b[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            diff += (i != j && a[i] == b[j]);
    cout << same << '\n' << diff << '\n';
    return 0;
}