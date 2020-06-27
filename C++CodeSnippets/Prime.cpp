/* -------------------------------------------------------------------------- */
/*                                 For storing                                */
/* -------------------------------------------------------------------------- */
#include <bits/stdc++.h>
using namespace std;

#define NN 47000
bool p[NN + 7];   // Hashing
vector<int> pr;   // storing prime
void sieve(int n) {
    int i, j, k, l;
    p[1] = 1;
    pr.push_back(2);
    for (i = 4; i <= n; i += 2) p[i] = 1;
    for (i = 3; i <= n; i += 2) {
        if (p[i] == 0) {
            pr.push_back(i);
            for (j = i * i; j <= n; j += 2 * i) p[j] = 1;
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                                 For Hashing                                */
/* -------------------------------------------------------------------------- */

#define NN 47000
bool p[NN + 7];   // Hashing
void sieve(int n) {
    int i, j, k, l;
    p[1] = 1;
    for (i = 4; i <= n; i += 2) p[i] = 1;
    for (i = 3; i * i <= n; i += 2) {
        if (p[i] == 0) {
            for (j = i * i; j <= n; j += 2 * i) p[j] = 1;
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                                   IsPrime                                  */
/* -------------------------------------------------------------------------- */

bool isprime(long long n) {
    if (n == 2)
        return 1;
    if (n == 1 || n % 2 == 0)
        return 0;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

/* -------------------------------------------------------------------------- */
/*                                Prime Factors                               */
/* -------------------------------------------------------------------------- */

int factor(int n) {
    int count, k, i;
    for (i = 0; i < pr.size() && pr[i] * pr[i] <= n; i++) {
        k = pr[i];
        count = 0;
        while (n % k == 0) {
            n /= k;
            count++;
        }
        if (n == 1)
            break;
    }
    if (n > 1) {
        count++;
        // then, n is another prime factor;
    }
}

/* -------------------------------------------------------------------------- */
/*                             Store Prime Factors                            */
/* -------------------------------------------------------------------------- */

vector<int> facts[NN + 7];

int get_factors(int n) {
    int k, i, r = n, count;
    for (i = 0; i < pr.size() && pr[i] * pr[i] <= n; i++) {
        k = pr[i];
        count = 0;

        if (n % k == 0)
            facts[r].push_back(k);
        while (n % k == 0) {
            n /= k;
            count++;
        }
        if (n == 1)
            break;
    }
    if (n > 1 && n != r) {
        facts[r].push_back(n);
        count++;
    }
}

int go(int n) {
    int i, j;
    sieve(n);
    for (i = 1; i <= n; i++) factor(i);
}