#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    if (x > y) swap(x, y);
    if (x < z and z < y)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}