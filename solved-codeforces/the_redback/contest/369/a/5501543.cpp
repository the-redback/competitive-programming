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
    int n, d, p;
    while (~scanf("%d%d%d", &n, &d, &p)) {
        int i, j, k, l;
        int ret = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &k);
            if (k == 1) {
                if (d > 0)
                    d--;
                else
                    ret++;
            } else if (k == 2) {
                if (p > 0)
                    p--;
                else if (d > 0)
                    d--;
                else
                    ret++;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
