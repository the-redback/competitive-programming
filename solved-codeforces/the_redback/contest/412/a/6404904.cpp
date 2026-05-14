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

string s;

main() {
    // ios_base::sync_with_stdio(false);
    int t, tc;
    int i, j, k, l, m, n;
    // cin>>tc;
    while (cin >> n >> k) {
        cin >> s;
        if (n - k < k) {
            for (i = 0; i < n - k; i++) puts("RIGHT");
            for (i = s.size() - 1; i >= 0; i--) {
                printf("PRINT %c\n", s[i]);
                if (i != 0) puts("LEFT");
            }
        } else {
            for (i = k; i > 1; i--) puts("LEFT");
            for (i = 0; i < s.size(); i++) {
                printf("PRINT %c\n", s[i]);
                if (i != s.size() - 1) puts("RIGHT");
            }
        }
    }
    return 0;
}
