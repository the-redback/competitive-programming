#include <bits/stdc++.h>
using namespace std;

string factorial[1001];

string multiply(string a, int n) {
    string result;
    int carry = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        int value = (a[i] - '0') * n + carry;

        result.push_back((value % 10) + '0');
        carry = value / 10;
    }

    while (carry > 0) {
        result.push_back((carry % 10) + '0');
        carry /= 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

void preprocess() {
    factorial[0] = "1";

    for (int i = 1; i <= 1000; i++) {
        factorial[i] = multiply(factorial[i - 1], i);
    }
}

int main() {
    preprocess();

    int n;

    while (cin >> n) {
        cout << n << "! : ";
        cout << factorial[n] << '\n';
    }

    return 0;
}
