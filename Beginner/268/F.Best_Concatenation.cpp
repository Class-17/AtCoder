#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll count(const string &s) {
    ll res = 0, x = 0;
    for (auto &c : s) {
        if (c == 'X') ++x;
        else res += x * (c - '0');
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> strs(n);
    for (auto &s : strs) cin >> s;
    sort(begin(strs), end(strs), [](const auto &a, const auto &b) {
        return count(a + b) > count(b + a);
    });
    string res;
    for (auto &s : strs) res += s;
    cout << count(res) << '\n';
    return 0;
}