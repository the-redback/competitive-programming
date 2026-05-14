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

int a[1010];

int main() {
    ios_base::sync_with_stdio(false);
    int t, tc;
    int i, j, k, l, m, n;
    // cin>>tc;
    while (cin >> n >> k) {
        for (i = 0; i < n; i++) {
            cin >> l;
            a[i] = l;
        }
        sort(a, a + n);
        int mx = inf;
        for (i = n - 1, j = 0; i >= 0, j < k; i--, j++) mx = min(a[i], mx);
        cout << mx << "\n";
    }
    return 0;
}
