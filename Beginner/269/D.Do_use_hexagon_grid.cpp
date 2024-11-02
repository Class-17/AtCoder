#include <bits/stdc++.h>
using namespace std;

constexpr int dirs[][2] {-1, -1, -1, 0, 0, -1, 0, 1, 1, 0, 1, 1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (auto &[x, y] : arr)
        cin >> x >> y;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i)
        mp[arr[i]] = i;
    vector<int> st(n);
    auto dfs = [&](auto &dfs, int idx) {
        if (st[idx]) return;
        st[idx] = 1;
        auto &[x, y] = arr[idx];
        for (auto &[dx, dy] : dirs) {
            auto [nx, ny] = pair{x + dx, y + dy};
            if (mp.find({nx, ny}) == mp.end()) continue;
            dfs(dfs, mp[{nx, ny}]);
        }
    };
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (st[i]) continue;
        dfs(dfs, i);
        ++res;
    }
    cout << res << '\n';
    return 0;
}