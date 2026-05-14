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

long long ncr(int n, int r) {
    int k, l;
    k = max(r, n - r);
    l = min(r, n - r);
    long long sum = 1;
    long long i;
    int j = 1;
    for (i = k + 1; i <= n; i++) {
        sum = (long long)sum * i;
        if (j <= l && sum % j == 0) {
            sum /= j;
            j++;
        }
    }
    return sum;
}

int main() {
    int n, k, l, r;
    int tc, t = 1;
    // scanf("%d",&tc);
    while (~scanf("%d%d", &n, &r)) {
        if (n == 0 && r == 0) return 0;
        long long sum = ncr(n, r);
        printf("%d things taken %d at a time is %lld exactly.\n", n, r, sum);
    }
    return 0;
}
