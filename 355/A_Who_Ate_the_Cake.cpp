#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    set<int> st{1, 2, 3};
    for (int i = 0; i < 2; ++i) {
        int x; cin >> x;
        if (st.count(x)) st.erase(x);
    }
    cout << (size(st) == 1 ? *begin(st) : -1);
    return 0;
}