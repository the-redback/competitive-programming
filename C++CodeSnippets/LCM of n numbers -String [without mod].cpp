/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include <bits/stdc++.h>
using namespace std;

#define inf       HUGE_VAL
#define mem(a, b) memset(a, b, sizeof(a))

bool pr[106];
vector<int> prim;
int mx;
int fact[10001];

void sieve(int n) {
    memset(pr, 0, sizeof(pr));
    long i, j, k, l;
    pr[1] = 1;
    prim.push_back(2);
    for (i = 4; i <= n; i += 2) pr[i] = 1;
    for (i = 3; i <= n; i += 2) {
        if (pr[i] == 0) {
            prim.push_back(i);
            for (j = i * i; j <= n; j += 2 * i) pr[j] = 1;
        }
    }
}

void factor(int n) {
    int i, j, count;
    for (j = 0; j < prim.size() && prim[j] * prim[j] <= n; j++) {
        i = prim[j];
        count = 0;
        if (n % i == 0) {
            mx = max(i, mx);
        }
        while (n % i == 0) {
            n /= i;
            count++;
        }
        fact[i] = max(fact[i], count);
        if (n == 1) break;
    }
    if (n > 1) {
        mx = max(n, mx);
        fact[n] = max(fact[n], 1);
    }
}

string s;
void mult(int n, int r) {
    while (r--) {
        long long k, i, carry = 0;
        for (i = 0; i < s.size(); i++) {
            k = s[i] - '0';
            k = (n * k) + carry;
            s[i] = k % 10 + '0';
            carry = k / 10;
        }
        while (carry > 0) {
            s += carry % 10 + '0';
            carry /= 10;
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    sieve(101);
    int n, k, i, m, c;
    int tc, t = 1;
    cin >> tc;
    while (tc--) {
        cin >> n;
        mem(fact, 0);
        mx = -inf;
        while (n--) {
            cin >> k;
            factor(k);
        }
        s = "1";
        for (i = 2; i <= mx; i++) {
            if (fact[i]) {
                mult(i, fact[i]);
            }
        }
        reverse(s.begin(), s.end());
        printf("Case %d: %s\n", t++, s.c_str());
    }
    return 0;
}

/*
Input:
2
3
2 20 10
4
5 6 30 60

Output:
Case 1: 20
Case 2: 60
*/
