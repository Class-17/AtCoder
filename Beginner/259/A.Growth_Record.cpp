#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    if (m >= x) cout << t << '\n';
    else        cout << t - (x - m) * d << '\n';
    return 0;
}