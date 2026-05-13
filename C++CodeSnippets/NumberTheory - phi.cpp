#include <iostream>
using namespace std;

// Euler's Totient Function.
// It returns: the number of integers from 1 to n
// that are coprime with n
int phi(int n) {
    int result = n;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }

            result -= result / i;
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

int main() {
    cout << phi(10) << '\n';

    return 0;
}
