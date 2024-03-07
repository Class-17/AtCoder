#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int h = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1)
            h = i;
        else
            b[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i, h = b[h])
        cout << h << " \n"[i == n];
    return 0;
}