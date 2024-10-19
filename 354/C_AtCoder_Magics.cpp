#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> c[i];
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    ranges::sort(ord, [&](const auto &i, const auto &j) {
        return a[i] > a[j];
    });
    int k = 1;
    for (int i = 1; i < n; ++i)
        if (c[ord[k - 1]] > c[ord[i]])
            ord[k++] = ord[i];
    ord.erase(begin(ord) + k, end(ord));
    ranges::sort(ord);
    cout << k << '\n';
    for (int i = 0; i < k; ++i)
        cout << ord[i] + 1 << " \n"[i + 1 == k];
    return 0;
}