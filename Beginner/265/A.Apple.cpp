#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int x, y, n;
    cin >> x >> y >> n;
    if (x * 3 < y)
        cout << x * n << '\n';
    else
        cout << n / 3 * y + (n % 3) * x << '\n';
    return 0;
}