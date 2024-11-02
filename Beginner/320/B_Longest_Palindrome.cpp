#include <bits/stdc++.h>
using namespace std;

bool check(const string &s) {
    int n = size(s);
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - 1 - i]) return false;
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s);
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (check(s.substr(i, j - i + 1)))
                res = max(res, j - i + 1);
    cout << res << '\n';
    return 0;
}