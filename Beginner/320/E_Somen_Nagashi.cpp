#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

using pii = pair<i64, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<i64> res(n);
    priority_queue<pii, vector<pii>, greater<>> pq;
    priority_queue<int, vector<int>, greater<>> pqId;
    for (int i = 0; i < n; ++i)
        pqId.emplace(i);
    for (int i = 0; i < m; ++i) {
        int t, w, s;
        cin >> t >> w >> s;
        while (!pq.empty() and pq.top().first <= t) {
            auto [x, id] = pq.top(); pq.pop();
            pqId.emplace(id);
        }
        if (pqId.empty()) continue;
        res[pqId.top()] += w;
        pq.emplace(t + s, pqId.top());
        pqId.pop();
    }
    for (auto &x : res)
        cout << x << '\n';
    return 0;
}