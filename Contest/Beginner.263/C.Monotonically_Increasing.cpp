#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> seq;
    auto dfs = [&](auto &dfs, int idx, int val) {
        if (idx == n) {
            for (int i = 0; i < n; ++i)
                cout << seq[i] << (i + 1 < n ? ' ' : '\n');
            return;
        }
        for (int i = val; i <= m; ++i) {
            seq.push_back(i);
            dfs(dfs, idx + 1, i + 1);
            seq.pop_back();
        }
    };
    dfs(dfs, 0, 1);
    return 0;
}