#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
    r = min(r, n - r);

    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result = result * (n - r + i) / i;
    }
    return result;
}

int main() {
    cout << nCr(5, 2) << '\n';
    return 0;
}
