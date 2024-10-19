#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> g(n + 1);
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> g[i];
        ind[g[i]] += 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (ind[i] == 0) q.push(i);
    i64 res = 0;
    vector<int> w(n + 1);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        w[u] += 1;
        int v = g[u];
        if (--ind[v] == 0)
            q.push(v);
        w[v] += w[u];
        res += w[u];
    }
    for (int i = 1; i <= n; ++i) {
        if (ind[i] <= 0) continue;
        i64 sum = 0, cnt = 0;
        int u = i;
        while (ind[u] > 0) {
            sum += w[u];
            cnt += 1;
            ind[u] = 0;
            u = g[u];
        }
        res += cnt * cnt;
        res += cnt * sum;
    }
    cout << res << '\n';
    return 0;
}