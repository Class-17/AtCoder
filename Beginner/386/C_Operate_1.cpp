#include <bits/stdc++.h>

bool check1(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i)
        cnt += (s[i] != t[i]);
    return cnt <= 1;
}

bool check2(std::string &s, std::string &t) {
    int n = s.size(), m = t.size(); 
    if (n + 1 != m) return false;
    std::vector<bool> left(m), right(m);
    left[0] = true;
    right.back() = true;
    for (int i = 1; i < m; ++i)
        left[i] = left[i - 1] && s[i] == t[i];
    for (int i = m - 2; i >= 0; --i)
        right[i] = right[i + 1] && s[i - 1] == t[i];
    for (int i = 1; i + 1 < m; ++i)
        if (left[i - 1] and right[i + 1]) return true;
    return false;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int k; std::cin >> k;
    std::string s, t;
    std::cin >> s >> t;
    if (s.size() > t.size()) std::swap(s, t);
    s = "#" + s + "#";
    t = "#" + t + "#";
    if (check1(s, t) or check2(s, t))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    return 0;
}