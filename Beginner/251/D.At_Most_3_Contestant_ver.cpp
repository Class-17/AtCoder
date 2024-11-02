#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 99;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int w; cin >> w;
    cout << lim * 3 << '\n';
    for (int i = 1; i <= lim; ++i) {
        cout << i << ' ' << i * 100 << ' ';
        cout << i * 10000 << (i < lim ? ' ' : '\n');
    }
    return 0;
}