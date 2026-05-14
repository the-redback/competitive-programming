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

#define mem(a, b) memset(a, b, sizeof(a))
#define pb        push_back
#define pp        pop_back
#define inf       10000000
#define NN        100010
int main() {
    double a, d, xxx, yyy;
    int n, i, roun;
    scanf("%lf %lf %d", &a, &d, &n);
    double len = d * 1;
    for (i = 1; i <= n; i++) {
        roun = len / (a * 4);

        len = len - (roun * 4 * a);
        // cout<<len<<endl;
        // cout<<len;
        if (len >= 0.0 && len <= a) {
            xxx = len;
            yyy = 0.0;
        } else if (len > a && len <= (2 * a)) {
            yyy = len - (a * 1.0);
            xxx = a;

        } else if (len > (2 * a) && len <= (3 * a)) {
            xxx = len - (a * 2.0);
            xxx = a - xxx;
            yyy = a;

        } else {
            xxx = 0.0;
            yyy = len - (a * 3.0);
            yyy = a - yyy;
        }

        printf("%.11lf %.11lf\n", xxx, yyy);
        len += d;
    }
    return 0;
}
