#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x % k == 0)
            cout << x / k << ' ';
    }
    return 0;
}