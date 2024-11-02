#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<pair<int, int>>> arr(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        auto &x = arr[i];
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int p, e;
            cin >> p >> e;
            arr[i].emplace_back(p, e);
            mp[p].push_back(e);
        }
    }
    for (auto &[p, e] : mp) {
        e.push_back(0);
        sort(rbegin(e), rend(e));
    }   
    vector<vector<pair<int, int>>> res;
    for (auto &num : arr) {
        vector<pair<int, int>> curr;
        for (auto &[p, e] : num) {
            if (e != mp[p][0] or mp[p][0] == mp[p][1]) continue;
            curr.emplace_back(p, mp[p][0] - mp[p][1]);
        }
        sort(begin(curr), end(curr));
        res.push_back(curr);
    }
    sort(begin(res), end(res));
    res.erase(unique(begin(res), end(res)), end(res));
    cout << size(res) << '\n';
    return 0;
}