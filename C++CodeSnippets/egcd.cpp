#include <bits/stdc++.h>
using namespace std;

int x, y;

int extendedGCD(int a, int b) {
    int x1 = 1, y1 = 0;
    int x2 = 0, y2 = 1;

    while (b > 0) {
        int q = a / b;
        int r = a % b;

        int nx = x1 - q * x2;
        int ny = y1 - q * y2;

        x1 = x2;
        x2 = nx;

        y1 = y2;
        y2 = ny;

        a = b;
        b = r;
    }

    x = x1;
    y = y1;

    return a;
}

int main() {
    int a = 30;
    int b = 18;

    int gcd = extendedGCD(a, b);

    cout << gcd << '\n';
    cout << x << " " << y << '\n';

    return 0;
}