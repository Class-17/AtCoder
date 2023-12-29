#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    if (s.find("ab") != string::npos or s.find("ba") != string::npos)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}