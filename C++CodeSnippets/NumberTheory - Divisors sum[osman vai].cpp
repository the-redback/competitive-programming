#include <cstdio>

#define NN 500003

long Sum[NN];

int main() {
    long t, n, i, j;
    for (i = 1; i < NN; i++) {
        for (j = 2 * i; j < NN; j += i) Sum[j] += i;
    }
    scanf("%ld", &t);
    while (t--) {
        scanf("%ld", &n);
        printf("%ld\n", Sum[n]);
    }
    return 0;
}
