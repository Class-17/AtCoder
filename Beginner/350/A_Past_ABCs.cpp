#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int num = stoi(s.substr(3));
    if (0 < num and num < 350 and num != 316)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}