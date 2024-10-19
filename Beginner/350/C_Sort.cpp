#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<pair<int, int>> res;
    for (int i = 1; i <= n; ++i) {
        while (a[i] != i) {
            res.emplace_back(minmax(i, a[i]));
            swap(a[i], a[a[i]]);
        }
    }
    cout << size(res) << '\n';
    for (auto &[i, j] : res)
        cout << i << ' ' << j << '\n';
    return 0;
}