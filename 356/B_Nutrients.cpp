#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) {
            int x; cin >> x;
            a[j] -= x;
        }}
    bool res = true;
    for (int i = 1; i <= m; ++i)
        if (a[i] > 0) res = false;
    cout << (res ? "Yes" : "No") << '\n';
    return 0;
}