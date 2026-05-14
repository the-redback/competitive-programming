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

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc;
    // cin>>tc;
    int i, j, k, l, m, n;
    while (cin >> n >> m) {
        k = min(n, m);
        if (k % 2 == 0)
            puts("Malvika");
        else
            puts("Akshat");
    }
    return 0;
}
