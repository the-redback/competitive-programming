#include <bits/stdc++.h>
using namespace std;

long long divide(string &a, long long divisor, string &result) {
    result.clear();

    long long remainder = 0;

    for (char ch: a) {
        remainder = remainder * 10 + (ch - '0');

        if (remainder >= divisor || !result.empty()) {
            result.push_back(remainder / divisor + '0');
            remainder %= divisor;
        }
    }

    if (result.empty()) {
        result = "0";
    }

    return remainder;
}
