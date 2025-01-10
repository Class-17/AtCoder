#include <bits/stdc++.h>

int check(int mask, int n) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (mask >> i & 1) {
            if (cnt == 0) return false;
            cnt -= 1;
        }
        else
            cnt += 1;
    return cnt == 0;
}

std::string f(int mask, int n) {
    std::string s;
    for (int i = 0; i < n; ++i)
        s.push_back((mask >> i & 1) ? ')' : '(');
    return s;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<std::string> res;
    for (int i = 0; i < (1 << n); ++i)
        if (check(i, n)) res.push_back(f(i, n));
    std::ranges::sort(res);
    for (auto &s : res)
        std::cout << s << '\n';
    return 0;
}