#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ps(n);
    for (auto &[x, y] : ps)
        cin >> x >> y;
    auto count = [&]()->string {
        if (k == 1) return "Infinity";
        map<tuple<int, int, int>, int> st;
        for (int i = 0; i < n; ++i) {
            auto &[x1, y1] = ps[i];
            for (int j = i + 1; j < n; ++j) {
                auto &[x2, y2] = ps[j];
                int a = y2 - y1, b = x1 - x2;
                if (a < 0 or (a == 0 and b < 0))
                    tie(a, b) = pair{-a, -b};
                tie(a, b) = pair{a / gcd(a, b), b / gcd(a, b)};
                int c = a * x1 + b * y1;
                ++st[tuple{a, b, c}];
            }
        }
        int cnt = 0;
        for (auto &[_, x] : st)
            cnt += (x >= k * (k - 1) / 2);
        return to_string(cnt);
    };
    cout << count() << '\n';
    return 0;
}