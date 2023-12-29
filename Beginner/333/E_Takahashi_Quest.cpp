#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (auto &[t, x] : arr)
        cin >> t >> x;
    map<int, int> mp;
    vector<int> pick(n);
    int prev = 0, maxc = 0;
    bool win = true;
    for (int i = n - 1; i >= 0; --i) {
        auto &[t, x] = arr[i];
        if (t == 1) {
            if (mp[x] == 0) continue;
            --mp[x];
            --prev;
            pick[i] = 1;
        }
        else {
            ++mp[x];
            maxc = max(maxc, ++prev);
        }
    }
    if (prev == 0) {
        cout << maxc << '\n';
        for (int i = 0; i < n; ++i)
            if (arr[i].first == 1)
                cout << pick[i] << " \n"[i + 1 == n];
    }
    else
        cout << -1 << '\n';
    return 0;
}