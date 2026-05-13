#include <iostream>
using namespace std;

const int MAXN = 1000000;

int divisors[MAXN + 1];
int best[MAXN + 1];

void preprocess() {
    int mx = 0;
    int num = 1;

    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            divisors[j]++;
        }

        if (divisors[i] >= mx) {
            mx = divisors[i];
            num = i;
        }

        best[i] = num;
    }
}

int main() {
    preprocess();

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        cout << best[n] << '\n';
    }

    return 0;
}
