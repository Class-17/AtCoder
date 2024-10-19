#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int n = size(s), m = size(t);
    int i = 0;
    for (int j = 0; j < m; ++j) {
        if (s[i] == t[j]) {
            cout << j + 1 << " ";
            ++i;
        }
    }
    return 0;
}