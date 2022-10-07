#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int r, c;
    cin >> r >> c;
    cout << (max(abs(r - 8), abs(c - 8)) % 2 ? "black" : "white") << '\n';
    return 0;
}