#include <bits/stdc++.h>
using namespace std;

//(m^n)%p;
long p;
long check(long m, long n) {
    int sum;
    if (n == 0)
        return 1;
    if (n % 2 == 0) {
        sum = check(m, n / 2);
        return ((sum % p) * (sum % p)) % p;
    } else {
        sum = check(m, n - 1);
        return ((m % p) * (sum % p)) % p;
    }
}

int main() {
    long m, n, sum;
    while (scanf("%ld %ld %ld", &m, &n, &p) == 3) {
        sum = check(m, n);
        printf("%ld\n", sum);
    }
    return 0;
}

// another way of bigmod
const int mod = 1e9 + 7;
int my_pow(int a, int b) {
    int r = 1;
    while (b) {
        if (b % 2)
            r = (long long)r * a % mod;
        b /= 2;
        a = (long long)a * a % mod;
    }
    return r;
}

// Another way
const int MOD = 1e9 + 7;
int Pow_log(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2) {
            ans = (1LL * ans * x) % MOD;
            p--;
        } else {
            x = (1LL * x * x) % MOD;
            p >>= 1;
        }
    }
    return ans;
}