#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<int, int, char>> cells(m);
    for (auto &[x, y, c] : cells)
        std::cin >> x >> y >> c;
    std::vector<std::pair<int, int>> ps;
    for (const auto &[x, y, c] : cells)
        if (c == 'B')
            ps.emplace_back(x, y);
    std::ranges::sort(ps, std::greater{});
    std::map<int, int> block;
    int lastY = 0;
    for (auto &[x, y] : ps) {
        if (block.count(x)) continue;
        lastY = std::max(lastY, y);
        block[x] = lastY;
    }
    for (const auto &[x, y, c] : cells) {
        if (c == 'B') continue;
        int blackY = block.lower_bound(x)->second;
        if (blackY >= y) {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << "Yes\n";
    return 0;
}