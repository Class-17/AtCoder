#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << (x1 ^ x2 ^ x3) << ' ' << (y1 ^ y2 ^ y3) << '\n';
    return 0;
}