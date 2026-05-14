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

#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define NN        1050
#define mod       1000000007

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, tc;
    // scanf("%d",&tc);
    long long i, j, k, l, m, n, x, y;
    while (cin >> x >> y) {
        cin >> n;
        if (n == 1)
            k = (x) % mod;
        else if (n == 2)
            k = (y) % mod;
        else {
            n -= 3;
            n = n % 6;
            if (n == 0)
                k = (y - x) % mod;
            else if (n == 1)
                k = (-x) % mod;
            else if (n == 2)
                k = (-y) % mod;
            else if (n == 3)
                k = (x - y) % mod;
            else if (n == 4)
                k = (x) % mod;
            else if (n == 5)
                k = (y) % mod;
        }
        k = (k + mod) % mod;
        printf("%I64d\n", k);
    }

    return 0;
}
