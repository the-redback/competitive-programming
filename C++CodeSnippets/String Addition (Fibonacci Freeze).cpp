#include <bits/stdc++.h>
using namespace std;

string fib[5001];

string add(string a, string b) {
    string result;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

void preprocess() {
    fib[0] = "0";
    fib[1] = "1";

    for (int i = 2; i <= 5000; i++) {
        fib[i] = add(fib[i - 1], fib[i - 2]);
    }
}

int main() {
    preprocess();
    int n;

    while (cin >> n) {
        cout << "The Fibonacci number for "
                << n << " is "
                << fib[n] << '\n';
    }

    return 0;
}
