#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m; cin >> m;
    vector<int> idx[3][10]{};
    for (int i = 0; i < 3; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j)
            idx[i][s[j] - '0'].push_back(j);
    }
    int res = INT_MAX;
    for (int d = 0; d < 10; ++d) {
        if (idx[0][d].empty() or idx[1][d].empty() or idx[2][d].empty())
            continue;
        for (auto &i : idx[0][d]) {
            for (auto &j : idx[1][d]) {
                int b = 0;
                while (j + b == i) b += m;
                for (auto &k : idx[2][d]) {
                    int c = 0;
                    while (k + c == i or k + c == j + b) c += m;
                    res = min(res, max({i, j + b, k + c}));
                }
            }
        }
    }
    cout << (res < INT_MAX ? res : -1) << '\n';
    return 0;
}