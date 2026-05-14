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

long long a[3030];

int main() {
    ios_base::sync_with_stdio(false);
    int t, tc;
    // cin>>tc;
    int i, j, k, l, m, n;
    int v;
    while (cin >> n >> v) {
        int cnt = 0;
        mem(a, 0);
        for (i = 1; i <= n; i++) {
            cin >> k >> l;
            a[k] += (long long)l;
        }
        __int64 sum = 0;
        int hand = 0;
        long long vv = v;
        for (i = 1; i <= 3005; i++) {
            hand = min(a[i - 1], vv);
            sum += (long long)hand;
            k = min(vv - hand, a[i]);
            sum += (long long)k;
            a[i] -= (long long)k;
        }
        printf("%I64d\n", sum);
    }
    return 0;
}
