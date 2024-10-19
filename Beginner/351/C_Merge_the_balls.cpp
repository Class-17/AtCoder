#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> stk;
    for (auto &x : arr) {
        stk.push_back(x);
        while (size(stk) >= 2) {
            int sz = size(stk);
            if (stk[sz - 1] != stk[sz - 2]) break;
            stk.pop_back();
            stk.back() += 1;
        }
    }
    cout << size(stk) << '\n';
    return 0;
}