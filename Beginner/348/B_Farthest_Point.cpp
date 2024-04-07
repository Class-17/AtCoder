#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int> &a, pair<int, int> &b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x * x + y * y;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> ps(n);
    for (auto &[x, y] : ps)
        cin >> x >> y;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = 1; j < n; ++j)
            if (dist(ps[i], ps[j]) > dist(ps[i], ps[k]))
                k = j;
        cout << k + 1 << '\n';
    }
    return 0;
}