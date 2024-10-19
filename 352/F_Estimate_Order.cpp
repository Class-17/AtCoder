#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> part;
    vector<int> belong(n + 1);
    for (int i = 1; i <= n; ++i) {
        belong[i] = i - 1;
        part.push_back(vector<int>(1, i));
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
    }
    return 0;
}