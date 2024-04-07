#include <bits/stdc++.h>
using namespace std;

constexpr int N = 7;
constexpr int H = 10;

int grid[H], a[N], b[N];

int n, h, w;

bool check(int _h, int _w, int r, int c) {
    if (r + _h > h or c + _w > w) return false;
    for (int i = 0; i < _h; ++i)
        if ((grid[r + i] >> c) & ((1 << _w) - 1) << c)
            return false;
    return true;
}

void color(int _h, int _w, int r, int c) {
    for (int i = 0; i < _h; ++i)
        grid[r + i] ^= ((1 << _w) - 1) << c;
}

bool dfs(int used, int r, int c) {
    while (r < h and c < w and grid[r] >> c & 1) {
        while (c < w and grid[r] >> c & 1) ++c;
        if (c == w) ++r, c = 0;
    }
    if (r == h) return true;
    for (int i = 0; i < n; ++i) {
        if (used >> i & 1) continue;
        if (check(a[i], b[i], r, c)) {
            color(a[i], b[i], r, c);
            if (dfs(used | (1 << i), r, c))
                return true;
            color(a[i], b[i], r, c);
        }
        if (a[i] == b[i]) continue;
        if (check(b[i], a[i], r, c)) {
            color(b[i], a[i], r, c);
            if (dfs(used | (1 << i), r, c))
                return true;
            color(b[i], a[i], r, c);
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> h >> w;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    cout << (dfs(0, 0, 0) ? "Yes" : "No") << '\n';
    return 0;
}