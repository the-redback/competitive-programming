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
#define inf       HUGE_VAL
#define mem(a, b) memset(a, b, sizeof(a))

int sii, si, tii, ti;
int egcd(int a, int b) {
    int r, q, s, t;
    sii = 1, si = 0;
    tii = 0, ti = 1;
    while (b > 0) {
        r = a % b;
        q = a / b;
        s = sii - (q * si);
        t = tii - (q * ti);
        sii = si, si = s;
        tii = ti, ti = t;
        a = b, b = r;
    }
    return a;
}

int main() {
    int tc, t = 1;
    int i, j, k, l, x;
    // scanf("%d",&tc);
    while (~scanf("%d%d", &x, &k)) {
        // printf("Case %d:\n",t++);
        l = egcd(x, k);
        printf("%d %d %d\n", sii, tii, l);
    }
    return 0;
}
