#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<pair<int, int>> ps(4);
    for (auto &[x, y] : ps)
        cin >> x >> y;
    auto check = [&]() {
        for (int i = 0; i < 4; ++i) {
            auto [x1, y1] = ps[i];
            auto [x2, y2] = ps[(i + 1) % 4];
            auto [x3, y3] = ps[(i + 2) % 4];
            if ((x2 - x1) * (y3 - y2)  <= (x3 - x2) * (y2 - y1)) return false;
        }
        return true;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}