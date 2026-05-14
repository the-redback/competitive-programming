/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;

#define ppb       pop_back
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1000000000
#define eps       1e-9
#define NN        400010

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int t, tc;
    int i, j, k, l, m, n, mn, mx, mnf, mxf, fl;
    // cin>>tc;
    while (cin >> n >> m >> mn >> mx) {
        fl = mnf = mxf = -1;
        for (i = 0; i < m; i++) {
            cin >> k;
            if (k == mn) mnf = 1;
            if (mx == k) mxf = 1;
            if (k < mn || k > mx) fl = 1;
        }
        if (m > n || fl == 1)
            puts("Incorrect");
        else if (mnf == 1 && mxf == 1) {
            puts("Correct");
        } else if ((mnf == 1 && mxf == -1) || (mnf == -1 && mxf == 1)) {
            if (n - m >= 1)
                puts("Correct");
            else
                puts("Incorrect");
        } else if (mnf == -1 && mxf == -1) {
            int r = 2;
            if (mx == mn) r = 1;
            if (n - m >= r)
                puts("Correct");
            else
                puts("Incorrect");
        } else
            puts("Incorrect");
    }
    return 0;
}
