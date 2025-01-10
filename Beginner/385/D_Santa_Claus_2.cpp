#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, m, sx, sy;
    std::cin >> n >> m >> sx >> sy;
    std::map<int, std::set<i64>> posX, posY;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        posX[x].insert(y);
        posY[y].insert(x);
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        char d; std::cin >> d;
        int c; std::cin >> c;
        if (d == 'U') {
            auto it = posX[sx].lower_bound(sy);
            while (it != posX[sx].end() and *it <= sy + c) {
                posY[*it].erase(sx);
                it = posX[sx].erase(it);
                res += 1;
            }
            sy += c;
        }
        else if (d == 'D') {
            auto it = posX[sx].lower_bound(sy - c);
            while (it != posX[sx].end() and *it <= sy) {
                posY[*it].erase(sx);
                it = posX[sx].erase(it);
                res += 1;
            }
            sy -= c;
        }
        else if (d == 'R') {
            auto it = posY[sy].lower_bound(sx);
            while (it != posY[sy].end() and *it <= sx + c) {
                posX[*it].erase(sy);
                it = posY[sy].erase(it);
                res += 1;
            }
            sx += c;
        }
        else if (d == 'L') {
            auto it = posY[sy].lower_bound(sx - c);
            while (it != posY[sy].end() and *it <= sx) {
                posX[*it].erase(sy);
                it = posY[sy].erase(it);
                res += 1;
            }
            sx -= c;
        }
    }
    std::cout << sx << ' ' << sy << ' ' << res << '\n';
    return 0;
}