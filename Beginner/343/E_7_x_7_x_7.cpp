#include <bits/stdc++.h>
using namespace std;

constexpr int N = 7;
constexpr int M = 7;

void add(int a[], int p) {
    for (int i = 0; i < N; ++i)
        ++a[i + p + M];
}

bool isIn(int x, int l, int r) {
    return l <= x <= r;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;
    int a1 = 0, b1 = 0, c1 = 0;
    for (int a2 = -N; a2 <= N; ++a2)
        for (int b2 = -N; b2 <= N; ++b2)
            for (int c2 = -N; c2 <= N; ++c2)
                for (int a3 = -N; a3 <= N; ++a3)
                    for (int b3 = -N; b3 <= N; ++b3)
                        for (int c3 = -N; c3 <= N; ++c3) {

                            int V1 = 0, V2 = 0, V3 = 0;
                            {
                                int x = 0, y = 0, z = 0;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(a1 + i, a2, a2 + N - 1) and !isIn(a1 + i, a3, a3 + N - 1)) ++x;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(b1 + i, b2, b2 + N - 1) and !isIn(b1 + i, b3, b3 + N - 1)) ++y;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(c1 + i, c2, c2 + N - 1) and !isIn(c1 + i, c3, c3 + N - 1)) ++z;
                                V1 += x * y * z;
                            }
                            {
                                int x = 0, y = 0, z = 0;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(a2 + i, a1, a1 + N - 1) and !isIn(a2 + i, a3, a3 + N - 1)) ++x;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(b2 + i, b1, b1 + N - 1) and !isIn(b2 + i, b3, b3 + N - 1)) ++y;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(c2 + i, c1, c1 + N - 1) and !isIn(b3 + i, c3, c3 + N - 1)) ++z;
                                V1 += x * y * z;
                            }
                            {
                                int x = 0, y = 0, z = 0;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(a3 + i, a2, a2 + N - 1) and !isIn(a3 + i, a1, a1 + N - 1)) ++x;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(b3 + i, b2, b2 + N - 1) and !isIn(b3 + i, b1, b1 + N - 1)) ++y;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(c3 + i, c2, c2 + N - 1) and !isIn(c3 + i, c1, c1 + N - 1)) ++z;
                                V1 += x * y * z;
                            }

                            {
                                int x = 0, y = 0, z = 0;
                                for (int i = 0; i < N; ++i)
                                    if (isIn(a3 + i, a2, a2 + N - 1) and !isIn(a3 + i, a1, a1 + N - 1)) ++x;
                                for (int i = 0; i < N; ++i)
                                    if (isIn(b3 + i, b2, b2 + N - 1) and !isIn(b3 + i, b1, b1 + N - 1)) ++y;
                                for (int i = 0; i < N; ++i)
                                    if (isIn(c3 + i, c2, c2 + N - 1) and !isIn(c3 + i, c1, c1 + N - 1)) ++z;
                                V2 += x * y * z;
                            }


                            {
                                int x = 0, y = 0, z = 0;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(a3 + i, a2, a2 + N - 1) and isIn(i, a1, a1 + N - 1)) ++x;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(b3 + i, b2, b2 + N - 1) and isIn(i, b1, b1 + N - 1)) ++y;
                                for (int i = 0; i < N; ++i)
                                    if (!isIn(c3 + i, c2, c2 + N - 1) and isIn(i, c1, c1 + N - 1)) ++z;
                                V2 += x * y * z;
                            }

                            {
                                int x = 0, y = 0, z = 0;
                                for (int i = 0; i < N; ++i)
                                    if (isIn(a3 + i, a2, a2 + N - 1) and isIn(i, a1, a1 + N - 1)) ++x;
                                for (int i = 0; i < N; ++i)
                                    if (isIn(b3 + i, b2, b2 + N - 1) and isIn(i, b1, b1 + N - 1)) ++y;
                                for (int i = 0; i < N; ++i)
                                    if (isIn(c3 + i, c2, c2 + N - 1) and isIn(i, c1, c1 + N - 1)) ++z;
                                V3 += x * y * z;
                            }

                            if (tuple{a2, b2, c2} == tuple{0, 6, 0} and tuple{a3, b3, c3} == tuple{6, 0, 0}) {
                                cout << V1 << ' ' << V2 << ' ' << V3 << '\n';
                            }

                            if (v1 == V1 and v2 == V2 and v3 == V3 ) {
                                cout << "Yes" << '\n';
                                cout << a1 << ' ' << b1 << ' ' << c1 << ' ';
                                cout << a2 << ' ' << b2 << ' ' << c2 << ' ';
                                cout << a3 << ' ' << b3 << ' ' << c3 << '\n';
                                return 0;
                            }
                        }
    cout << "No" << '\n';
    return 0;
}