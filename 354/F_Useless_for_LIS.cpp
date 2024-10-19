#include <bits/stdc++.h>
using namespace std;


set<int> prefLIS(vector<int> &a) {
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            int p = lower_bound(begin(st), end(st), a[i]) - begin(st);
            if (p >= size(st))
                st.push_back(p);
            else
                st[p] = a[i];
        }
        vector<int> res;
        int last = n + 1;
        for (int i = n - 1; i >= 0; --i) {
            if (idx[i] < last)
                res.push_back(i);
            last = min(last, idx[i]);
        }
        ranges::sort(res);
        cout << size(res) << '\n';
        for (int i = 0; i < size(res); ++i)
            cout << res[i] + 1 << " \n"[i + 1 == size(res)];
    }
    return 0;
}