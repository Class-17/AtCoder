#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::map<int, int> cnt;
    for (int i = 0; i < 4; ++i) {
        int x; std::cin >> x;
        cnt[x] += 1;
    }
    int a = cnt.begin()->second;
    int b = cnt.rbegin()->second;
    if (a < b) std::swap(a, b);
    if ((a == 2 and b == 2) or (a == 3 and b == 1))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    return 0;
}