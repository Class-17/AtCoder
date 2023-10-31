#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    if (x > y)
        cout << (x - y <= 3 ? "Yes" : "No") << '\n';
    else
        cout << (y - x <= 2 ? "Yes" : "No") << '\n';
    return 0;
}