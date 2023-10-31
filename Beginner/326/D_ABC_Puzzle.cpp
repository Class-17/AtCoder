#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    vector<string> mat;
    vector cnt(n, array{0, 0, 0});
    auto dfs = [&](auto &dfs, int row) {
        if (row == n) {
            for (int j = 0; j < n; ++j) {
                int i = 0;
                while (i < n and mat[i][j] == '.') ++i;
                if (i >= n or mat[i][j] != t[j]) return false;
            }
            return true;
        }
        string curr = string(n - 3, '.') + "ABC";
        do {
            int j = 0;
            while (j < n and curr[j] == '.') ++j;
            if (j >= n or curr[j] != s[row]) continue;

            for (int i = 0; i < n; ++i)
                if (curr[i] != '.')
                    ++cnt[i][curr[i] - 'A'];
            bool error = false;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < 3; ++j)
                    if (cnt[i][j] > 1) error = true;

            mat.push_back(curr);
            if (!error and dfs(dfs, row + 1)) return true;
            mat.pop_back();

            for (int i = 0; i < n; ++i)
                if (curr[i] != '.')
                    --cnt[i][curr[i]- 'A'];
        } while(next_permutation(begin(curr), end(curr)));
        return false;
    };
    if (dfs(dfs, 0)) {
        cout << "Yes" << '\n';
        for (auto &row : mat)
            cout << row << '\n';
    }
    else {
        cout << "No" << '\n';
    }
    return 0;
}