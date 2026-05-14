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
#define inf HUGE_VAL

int main() {
    int tc, t = 1;
    int i, j, k, n, c;

    while (~scanf("%d%d", &n, &c)) {
        int d = n;
        int xtra = 0;
        int sum = n;
        while (d >= c) {
            xtra = d % c;
            sum = sum + (d / c);
            d = (d / c);
            d = d + xtra;
        }
        printf("%d\n", sum);
    }
    return 0;
}
