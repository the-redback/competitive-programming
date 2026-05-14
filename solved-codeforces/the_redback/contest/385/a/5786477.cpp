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
#define NN        5000
int a[1000];
int main() {
    int tc, t = 1;
    int i, j, k, l, m, n, count;
    // scanf("%d",&tc);
    while (~scanf("%d%d", &n, &m)) {
        count = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n - 1; i++) count = max(count, a[i] - a[i + 1] - m);
        printf("%d\n", count);
    }
    return 0;
}
