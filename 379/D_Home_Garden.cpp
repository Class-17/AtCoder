#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::queue<i64> q;
    i64 base = 0;
    while (n--) {
        int t; std::cin >> t;
        if (t == 1) {
            q.push(-base);
        }
        else if (t == 2) {
            int x; std::cin >> x;
            base += x;
        }
        else {
            int h; std::cin >> h;
            int cnt = 0;
            while (!q.empty() and q.front() + base >= h) {
                q.pop();
                cnt += 1;
            }
            std::cout << cnt << '\n';
        }
    }
    return 0;
}