#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template<class T>
class FenwickTree {
// fenwickTree for interval [1, n]
private:
    int n;
    vector<T> sum;
    int lowbit(int x) {return x & -x;}
public:
    FenwickTree(int n = 0) : n(n), sum(n + 1) {}
    
    void add(int x, T d) {
        for (; x <= n; x += lowbit(x))
            sum[x] += d;
    }
    // return sum of [1, x]
    T ask(int x) {
        T res = 0;
        for (; x; x -= lowbit(x))
            res += sum[x];
        return res;
    }
    // return sum of [l, r]
    T ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
};

map<i64, int> gen(vector<i64> &arr) {
    map<i64, int> mp;
    for (auto &x : arr)
        mp[x] = 0;
    int i = 1;
    for (auto &[x, v] : mp)
        v = i++;
    return mp;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<i64> arr(n);
    for (auto &x : arr) cin >> x;
    auto mp = gen(arr);
    int m = size(mp);
    FenwickTree<i64> ft1(m), ft2(m);
    i64 res = 0;
    for (auto &x : arr) {
        int i = mp[x];
        i64 c = ft1.ask(i), v = ft2.ask(i);
        res += x * c - v;
        ft1.add(i, 1);
        ft2.add(i, x);
    }
    cout << res << '\n';
    return 0;
}