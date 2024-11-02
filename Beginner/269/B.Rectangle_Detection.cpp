#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<string> mat(10);
    for (auto &x : mat) cin >> x;
    int a = 10, b = 0;
    int c = 10, d = 0;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            if (mat[i][j] == '#') {
                a = min(a, i);
                b = max(b, i);
                c = min(c, j);
                d = max(d, j);
            }
    cout << a + 1 << ' ' << b + 1 << '\n';
    cout << c + 1 << ' ' << d + 1 << '\n';
    return 0;
}