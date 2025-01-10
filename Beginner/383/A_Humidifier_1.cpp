#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    int tot = 0, prev = 0;
    for (int i = 0; i < n; ++i) {
        int t, v;
        std::cin >> t >> v;
        tot = std::max(0,  tot - (t - prev));
        tot += v;
        prev = t;
    }
    std::cout << tot << '\n';
    return 0;
}