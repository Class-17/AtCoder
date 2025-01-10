#include <bits/stdc++.h>
#include <atcoder/dsu>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::tuple<int, int, int>> es(m);
    for (auto &[w, u, v] : es)
        std::cin >> u >> v >> w;
    std::ranges::sort(es);
    std::vector<int> cntA(n + 1), cntB(n + 1);
    for (int i = 0; i < k; ++i) {
        int x; std::cin >> x;
        cntA[x] += 1;
    }
    for (int i = 0; i < k; ++i) {
        int x; std::cin >> x;
        cntB[x] += 1;
    }
    i64 res = 0;
    atcoder::dsu d(n + 1);
    for (auto &[w, u, v] : es) {
        if (d.same(u, v)) continue;
        int ru = d.leader(u), rv = d.leader(v);
        int root = d.merge(ru, rv);
        cntA[root] = cntA[ru] + cntA[rv];
        cntB[root] = cntB[ru] + cntB[rv];
        i64 minus = std::min(cntA[root], cntB[root]);
        res += minus * w;
        cntA[root] -= minus;
        cntB[root] -= minus;
    }
    std::cout << res << '\n';
    return 0;
}