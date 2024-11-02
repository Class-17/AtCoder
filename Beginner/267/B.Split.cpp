#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    vector<int> a(7);
    a[0] = s[6] - '0';
    a[1] = s[3] - '0';
    a[2] = (s[1] - '0') | (s[7] - '0');
    a[3] = (s[0] - '0') | (s[4] - '0');
    a[4] = (s[2] - '0') | (s[8] - '0');
    a[5] = s[5] - '0';
    a[6] = s[9] - '0';
    auto check = [&]() {
        if (s[0] == '1') return false;
        for (int i = 0; i < 7; ++i)
            for (int j = i + 1; j < 7; ++j) {
                if (a[i] == 0 or a[j] == 0) continue;
                for (int k = i + 1; k < j; ++k) 
                    if (a[k] == 0) return true;
            }
        return false;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}