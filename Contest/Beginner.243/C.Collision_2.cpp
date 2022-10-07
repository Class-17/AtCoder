#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y, d;
    bool operator < (const point &p) {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<point> ps(n);
    for (auto &[x, y, _] : ps)
        cin >> x >> y;
    string s; cin >> s;
    for (int i = 0; i < n; ++i)
        ps[i].d = (s[i] == 'R');
    sort(begin(ps), end(ps));
    auto check = [&]() {
        auto collision = [&](int l, int r) {
            int d = 0;
            while (l < r) {
                if (d && !ps[l].d) return true;
                d |= ps[l].d;
                ++l;
            }
            return false;
        };
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n && ps[j].y == ps[i].y) ++j;
            if (collision(i, j)) return true;
            i = j - 1;
        }
        return false;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}