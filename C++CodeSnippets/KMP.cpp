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

typedef long long ll;
typedef unsigned long long llu;

#define NN 10010

ll fail[NN];  // Highest Prefix which equals as postfix at i.
char s[NN];   // Main String.
char p[NN];   // Find P-string in main string.

void failure(void) {
    ll i, j, k, l;
    ll m = strlen(p);

    fail[0] = 0;
    ll q = 0;

    for (i = 1; i < m; i++) {  // starts from 1, not 0.
        while (q > 0 && p[i] != p[q]) q = fail[q - 1];

        if (p[i] == p[q]) q++;
        fail[i] = q;
    }
    return;
}

ll KMP(void) {
    ll i, j, k, l, cnt = 0;
    ll m = strlen(p);
    l = strlen(s);

    failure();
    ll q = 0;

    for (i = 0; i < l; i++) {
        while (q > 0 && s[i] != p[q]) q = fail[q - 1];

        if (s[i] == p[q]) q++;
        if (q == m) {
            q = fail[q - 1];
            cnt++;  // we got one substring
        }
    }
    return cnt;
}

int main() {
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt", "r", stdin);
#endif

    ll t = 1, tc;
    scanf("%lld", &tc);
    ll i, j, k, l, m, n;
    while (tc--) {
        scanf("%s", &s);
        scanf("%s", &p);
        ll ans = KMP();
        printf("Case %lld: %lld\n", t++, ans);
    }
    return 0;
}
