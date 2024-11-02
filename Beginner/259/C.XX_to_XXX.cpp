#include <bits/stdc++.h>
using namespace std;

int move_p(const string &s, int p) {
    for (int i = p; i < size(s); ++i)
        if (s[i] != s[p]) return i;
    return size(s);
}

bool f(const string &a, const string &b) {
    int n = size(a), m = size(b);
    int i = 0, j = 0;
    while (i < n and j < m) {
        if (a[i] != b[j]) return false;
        int ii = move_p(a, i), jj = move_p(b, j);
        if (ii - i > jj - j) return false;
        if (jj - j >= 2 and ii - i <= 1) return false;
        tie(i, j) = pair{ii, jj};
    }
    return i == n and j == m;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    cout << (f(a, b) ? "Yes" : "No") << '\n';
    return 0;
}