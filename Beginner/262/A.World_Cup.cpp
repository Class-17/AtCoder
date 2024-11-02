#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int y; cin >> y;
    while (y % 4 != 2) ++y;
    cout << y << '\n';
    return 0;
}