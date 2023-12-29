#include <bits/stdc++.h>
using namespace std;

constexpr int N = 9;

int mat[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> mat[i][j];
    for (int i = 0; i < N; ++i) {
        int cnt[N + 1]{};
        for (int j = 0; j < N; ++j)
            if (++cnt[mat[i][j]] > 1) {
                cout << "No" << '\n';
                return 0;
            }
    }
    for (int j = 0; j < N; ++j) {
        int cnt[N + 1]{};
        for (int i = 0; i < N; ++i)
            if (++cnt[mat[i][j]] > 1) {
                cout << "No" << '\n';
                return 0;
            }
    }
    for (int i = 0; i < N; i += 3)
        for (int j = 0; j < N; j += 3) {
            int cnt[N + 1]{};
            for (int r = 0; r < 3; ++r)
                for (int c = 0; c < 3; ++c)
                    if (++cnt[mat[i + r][j + c]] > 1) {
                        cout << "No" << '\n';
                        return 0;
                    }
        }
    cout << "Yes" << '\n';
    return 0;
}