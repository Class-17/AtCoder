#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

bool check(i64 x) {
    string s = to_string(x);
    int n = size(s);
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - 1 - i]) return false;
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n; cin >> n;
    i64 res = 1;
    for (i64 i = 1; i * i * i <= n; ++i)
        if (check(i * i * i)) res = i * i * i;
    cout << res << '\n';
    return 0;
}