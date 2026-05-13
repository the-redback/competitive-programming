#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

unsigned long long phi[MAXN + 1];

void sieve() {
    for (int i = 1; i <= MAXN; i++) {
        phi[i] = i;
    }

    for (int i = 2; i <= MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MAXN; j += i) {
                phi[j] *= (i - 1);
                phi[j] /= i;
            }
        }
    }
}

int main() {
    sieve();

    cout << phi[10] << '\n';

    return 0;
}
