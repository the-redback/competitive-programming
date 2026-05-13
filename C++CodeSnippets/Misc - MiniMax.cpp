#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int pr[NN + 7];
int a[NN + 7][NN + 7];

int main() {
    int i, j, k, l, n, r, c, count;
    int tc, t = 1;
    int u, v, w;
    while (cin >> n >> r >> l) {
        if (n == 0 && r == 0 && l == 0) return 0;
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) a[i][j] = inf;
            a[i][i] = 0;
        }

        while (r--) {
            cin >> u >> v >> w;
            a[u][v] = w;
            a[v][u] = w;
        }

        for (k = 1; k <= n; k++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    a[i][j] = min(a[i][j], max(a[i][k], a[k][j]));
                }
            }
        }

        if (t != 1) puts("");
        cout << "Case #" << t++ << "\n";

        while (l--) {
            cin >> n >> r;
            int sum = a[n][r];
            if (sum >= inf)
                cout << "no path" << "\n";
            else
                cout << sum << "\n";
        }
    }
    return 0;
}
