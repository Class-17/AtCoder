#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    iota(begin(a), end(a), 0);
    reverse(begin(a) + l, begin(a) + r + 1);
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " \n"[i == n];
    return 0;
}