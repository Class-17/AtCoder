#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::string s; std::cin >> s;
    std::vector<std::vector<int>> nxt(n, std::vector<int>(26, n));
    for (int i = n - 1; i >= 0; --i)
        nxt[i][s[i] - 'a'] = i;
    for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j < 26; ++j)
            nxt[i][j] = std::min(nxt[i][j], nxt[i + 1][j]);
    auto select = [&](int p, int cnt) {
        for (int i = 0; i < 26; ++i)
            if (nxt[p][i] + cnt < n)
                return nxt[p][i];
        return -1;
    };
    int p = -1;
    while (k--) {
        p = select(p + 1, k);
        assert(p != -1);
        std::cout << s[p];
    }
    return 0;
}