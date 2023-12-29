#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, s, k;
    cin >> n >> s >> k;
    int cost = 0;
    for (int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;
        cost += p * q;
    }
    if (cost < s) cost += k;
    cout << cost << '\n';
    return 0;
}