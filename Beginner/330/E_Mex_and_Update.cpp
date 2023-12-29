#include <bits/stdc++.h>
using namespace std;

using Itv = pair<int, int>;

set<Itv> init(vector<int> arr) {
    set<Itv> itvs;
    sort(begin(arr), end(arr));
    arr.erase(unique(begin(arr), end(arr)), end(arr));
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (j < n and arr[j] == arr[j - 1] + 1) ++j;
        itvs.emplace(arr[i], arr[j - 1]);
        i = j - 1;
    }
    return itvs;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    map<int, int> cnt;
    for (auto &x : arr)
        ++cnt[x];
    auto itvs = init(arr);
    for (int i = 0; i < q; ++i) {
        int idx, x;
        cin >> idx >> x;
        --idx;
        if (--cnt[arr[idx]] == 0) {
            auto it = prev(itvs.lower_bound(Itv{arr[idx] + 1, arr[idx]}));
            auto [l, r] = *it;
            itvs.erase(it);
            itvs.emplace(l, arr[idx] - 1);
            itvs.emplace(arr[idx] + 1, r);
        }
        arr[idx] = x;
        if (++cnt[arr[idx]] == 1) {
            auto itR = itvs.lower_bound({arr[idx] + 1, arr[idx]});
            auto itL = (itR != begin(itvs) ? prev(itR) : end(itvs));
            int l = arr[idx], r = arr[idx];
            if (itL != end(itvs) and itL->second + 1 == l) {
                l = itL->first;
                itvs.erase(itL);
            }
            if (itR != end(itvs) and itR->first == r + 1) {
                r = itR->second;
                itvs.erase(itR);
            }
            itvs.emplace(l, r);
        }
        auto [l, r] = *begin(itvs);
        if (l > 0)
            cout << 0 << '\n';
        else
            cout << r + 1 << '\n';
    }
    return 0;
}