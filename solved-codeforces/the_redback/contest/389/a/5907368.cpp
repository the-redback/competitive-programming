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
#define inf       1000000000
#define NN        30

vector<int> v;

int main() {
    int tc, t = 1, ret = 0;
    int i, j, k, l, r;
    int n, m;
    int a[111];
    while (~scanf("%d", &n)) {
        scanf("%d", &ret);
        for (i = 1; i < n; i++) {
            scanf("%d", &k);
            ret = __gcd(ret, k);
        }
        ret *= n;
        printf("%d\n", ret);
    }
    return 0;
}
