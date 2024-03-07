#include <bits/stdc++.h>
using namespace std;


pair<int, int> move(pair<int, int> p, char d) {
    auto &[x, y] = p;
    if (d == 'R') x += 1;
    else if (d == 'L') x -= 1;
    else if (d == 'U') y += 1;
    else if (d == 'D') y -= 1;
    return p;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    deque<pair<int, int>> q;
    for (int i = 1; i <= n; ++i)
        q.emplace_back(i, 0);
    for (int i = 0; i < m; ++i) {
        int op; cin >> op;
        if (op == 1) {
            char d; cin >> d;
            auto p = move(q.front(), d);
            q.push_front(p);
            q.pop_back();
        }
        else {
            int p; cin >> p;
            auto &[x, y] = q[p-1];
            cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}