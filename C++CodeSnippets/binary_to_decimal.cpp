#include <bits/stdc++.h>
using namespace std;

long long binaryToDecimal(string bi) {
    long long ans = 0;
    long long carry = 1;

    for (int i = bi.size() - 1; i >= 0; i--) {
        if (bi[i] == '1') {
            ans += carry;
        }
        carry = carry << 1;
    }
    return ans;
}
