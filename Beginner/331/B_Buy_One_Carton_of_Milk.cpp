#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int res = INT_MAX;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
                if (i * 6 + j * 8 + k * 12 >= n)
                    res = min({res, i * a + j * b + k * c});
    cout << res << '\n';
    return 0;
}