#include <bits/stdc++.h>

main() {
    long long n;
    long k;
    while (scanf("%lld", &n)) {
        if (n == 0) {
            break;
        }
        k = sqrt(n);
        k = k * k;
        if (k == n) {
            printf("yes\n");
        } else if (k != n) {
            printf("no\n");
        }
    }
    return 0;
}
