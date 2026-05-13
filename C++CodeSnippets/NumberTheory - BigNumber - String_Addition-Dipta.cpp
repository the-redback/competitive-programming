#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    string ans;
    int tmp, carry = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
        if (i < 0)
            tmp = carry + b[j] - '0';
        else if (j < 0)
            tmp = carry + a[i] - '0';
        else
            tmp = carry + (a[i] - '0') + (b[j] - '0');

        carry = tmp / 10;
        ans += (tmp % 10) + '0';
    }
    if (carry) ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}
