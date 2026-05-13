#include <cstring>
using namespace std;

unsigned base[46656 / 64], segment[100032 / 64], primes[4830];

/* Generates all the necessary prime numbers and marks them in base[]*/
void sieve() {
    unsigned i, j, k;
    for (i = 3; i < 216; i += 2) {
        if (!(base[i >> 6] & (1 << ((i >> 1) & 31)))) {
            for (j = i * i, k = i << 1; j < 46656; j += k) {
                (base[j >> 6] |= (1 << ((j >> 1) & 31)));
            }
        }
    }
    for (i = 3, j = 0; i < 46656; i += 2) {
        if (!(base[i >> 6] & (1 << ((i >> 1) & 31)))) {
            primes[j++] = i;
        }
    }
}

/* Returns the prime-count within range [a,b] and marks them in segment[] */
int segmented_sieve(int a, int b) {
    unsigned i, j, k, cnt = (a <= 2 && 2 <= b) ? 1 : 0;
    if (b < 2) return 0;
    if (a < 3) a = 3;
    if (a % 2 == 0) a++;
    memset(segment, 0, sizeof(segment));
    for (i = 0; ((primes[i]) * (primes[i])) <= b; i++) {
        j = primes[i] * ((a + primes[i] - 1) / primes[i]);
        if (j % 2 == 0) {
            j += primes[i];
        }
        for (k = primes[i] << 1; j <= b; j += k) {
            if (j != primes[i]) {
                (segment[(j - a) >> 6] |= (1 << (((j - a) >> 1) & 31)));
            }
        }
    }
    for (i = 0; i <= b - a; i += 2)
        if (!(segment[i >> 6] & (1 << ((i >> 1) & 31)))) cnt++;
    return cnt;
}
