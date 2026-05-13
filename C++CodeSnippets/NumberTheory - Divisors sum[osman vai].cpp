#include <iostream>
using namespace std;

#define NN 500003

long Sum[NN];

int main() {
    long t, n, i, j;
    for (i = 1; i < NN; i++) {
        for (j = 2 * i; j < NN; j += i) Sum[j] += i;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << Sum[n] << "\n";
    }
    return 0;
}
