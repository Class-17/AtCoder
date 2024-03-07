#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	string s; cin >> s;
	set st{n};
	for (int i = 1; i < n; ++i)
		if (s[i] == s[i - 1]) st.insert(i);
	auto flip = [&](int x) {
		if (st.contains(x))
			st.erase(x);
		else
			st.insert(x);
	};
	for (int i = 0; i < q; ++i) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			if (l > 1) flip(l-1);
			if (r < n) flip(r);
		}
		else {
            if (*st.lower_bound(l) >= r)
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
		}
	}
	return 0;
}