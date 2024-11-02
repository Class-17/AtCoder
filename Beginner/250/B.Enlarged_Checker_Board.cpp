#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n * a; ++i) {
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < b; ++k)
                cout << ((i / a + j) & 1 ? '#' : '.');
        cout << '\n';
    }
    return 0;
}