#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h; cin >> h;
    for (int i = 0; i < 31; ++i) {
        if ((1 << i) - 1 > h) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}