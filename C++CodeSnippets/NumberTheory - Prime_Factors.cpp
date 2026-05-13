#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 1000000;

/* -------------------------------------------------------------------------- */
/*                                    Sieve                                   */
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
/*                              Prime Factorization                           */
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

int main() {
    int n = 5000;

    // Sieve

    sieve(n);

    cout << "Primes up to "
         << n
         << ":\n";

    for (int prime : primes) {
        cout << prime << " ";
    }

    cout << "\n\n";

    // Prime Factorization

    int num = 60;

    cout << "Prime factorization of "
         << num
         << ":\n";

    vector<pair<int, int> > factors =
        factorize(num);

    for (pair<int, int> factor : factors) {
        cout << factor.first
             << "^"
             << factor.second
             << '\n';
    }

    return 0;
}