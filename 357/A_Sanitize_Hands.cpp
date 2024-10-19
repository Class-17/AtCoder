#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        m -= x;
        if (m < 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    return 0;
}