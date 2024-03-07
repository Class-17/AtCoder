#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a += x;
        b += y;
    }
    if (a > b)
        cout << "Takahashi" << '\n';
    else if (a < b)
        cout << "Aoki" << '\n';
    else
        cout << "Draw" << '\n';
    return 0;
}