#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    map<int, int> mp;
    for (int i = 0; i < 5; ++i) {
        int x; cin >> x;
        ++mp[x];
    }
    auto check = [&]() {
        if (size(mp) != 2) return false;
        for (auto &[val, cnt] : mp)
            if (cnt == 2 or cnt == 3) return true;
        return false;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}