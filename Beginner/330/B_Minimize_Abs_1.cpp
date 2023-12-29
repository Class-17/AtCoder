#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        cout << clamp(a, l, r) << " \n"[i + 1 == n];
    }
    return 0;
}