#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int sum = 0, res = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (sum + x > k) {
            sum = x;
            res += 1;
        }
        else
            sum += x;
    }
    cout << res << '\n';
    return 0;
}