#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 1000000;

/* -------------------------------------------------------------------------- */
/*                                 For Storing                                */
/* -------------------------------------------------------------------------- */

bool visited[MAXN + 1];
vector<int> primes;

void sieve(int n) {
    visited[1] = true;
    primes.push_back(2);

    for (int i = 4; i <= n; i += 2) {
        visited[i] = true;
    }

    for (int i = 3; i <= n; i += 2) {
        if (!visited[i]) {
            primes.push_back(i);

            for (int j = i * i; j <= n; j += 2 * i) {
                visited[j] = true;
            }
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                                 For Hashing                                */
/* -------------------------------------------------------------------------- */

bool prime[MAXN + 1];

void sieveHash(int n) {
    prime[1] = true;

    for (int i = 4; i <= n; i += 2) {
        prime[i] = true;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (!prime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                prime[j] = true;
            }
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                                   IsPrime                                  */
/* -------------------------------------------------------------------------- */

bool isPrime(long long n) {
    if (n == 2) {
        return true;
    }

    if (n == 1 || n % 2 == 0) {
        return false;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

/* -------------------------------------------------------------------------- */
/*                                Prime Factors                               */
/* -------------------------------------------------------------------------- */

vector<pair<int, int> > factorize(int n) {
    vector<pair<int, int> > factors;

    for (int prime: primes) {
        if (1LL * prime * prime > n) {
            break;
        }

        if (n % prime == 0) {
            int count = 0;

            while (n % prime == 0) {
                n /= prime;
                count++;
            }
            factors.push_back({prime, count});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

/* -------------------------------------------------------------------------- */
/*                             Store Prime Factors                            */
/* -------------------------------------------------------------------------- */

vector<int> factors[MAXN + 1];

void getFactors(int n) {
    int original = n;

    for (int prime: primes) {
        if (prime * prime > n) {
            break;
        }

        if (n % prime == 0) {
            factors[original].push_back(prime);

            while (n % prime == 0) {
                n /= prime;
            }
        }
    }
    if (n > 1 && n != original) {
        factors[original].push_back(n);
    }
}

void preprocessFactors(int n) {
    sieve(n);

    for (int i = 1; i <= n; i++) {
        getFactors(i);
    }
}

int main() {
    int n = 5000;

    // Sieve

    sieve(n);

    cout << "Primes up to " << n << ":\n";

    for (int prime : primes) {
        cout << prime << " ";
    }

    cout << "\n\n";

    // Is Prime

    cout << "Is 37 prime?\n";

    if (isPrime(37)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    cout << "\n";

    // Prime Factorization

    int num = 60;

    cout << "Prime factorization of "
         << num
         << ":\n";

    vector<pair<int, int> > factorsList =
        factorize(num);

    for (pair<int, int> factor : factorsList) {
        cout << factor.first
             << "^"
             << factor.second
             << '\n';
    }

    cout << "\n";

    // Store Prime Factors

    preprocessFactors(n);

    cout << "Distinct prime factors of 60:\n";

    for (int factor : factors[60]) {
        cout << factor << " ";
    }

    cout << '\n';

    return 0;
}