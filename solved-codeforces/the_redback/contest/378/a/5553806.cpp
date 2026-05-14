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
    int i, j, k, n, w, d, l;
    while (~scanf("%d%d", &n, &k)) {
        w = 0;
        l = 0;
        d = 0;
        for (int x = 1; x < 7; x++) {
            if (abs(x - n) < abs(x - k))
                w++;
            else if (abs(x - n) > abs(x - k))
                l++;
            else if (abs(x - n) == abs(x - k))
                d++;
        }

        printf("%d %d %d\n", w, d, l);
    }
    return 0;
}
