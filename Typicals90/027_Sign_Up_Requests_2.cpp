#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::set<std::string> st;
    for (int i = 1; i <= n; ++i) {
        std::string s; std::cin >> s;
        if (st.count(s)) continue;
        st.insert(s);
        std::cout << i << '\n';
    }
    return 0;
}