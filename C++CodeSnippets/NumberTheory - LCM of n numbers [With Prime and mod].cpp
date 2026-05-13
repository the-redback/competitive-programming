/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#define inf 1e9
#define NN 10010

vector<int> arr;

bool pr[350];
vector<int> prim;
int mx;
int fact[NN];
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

int bigmod(int m, int n) {
    int sum;
    if (n == 0) return 1;
    if (n % 2 == 0) {
        sum = bigmod(m, n / 2);
        return ((sum % 1000000007) * (sum % 1000000007)) % 1000000007;
    } else {
        sum = bigmod(m, n - 1);
        return ((m % 1000000007) * (sum % 1000000007)) % 1000000007;
    }
}

int LCM(void) {  // LCM of elemets of arr with 1000000007
    long long sum;
    int i, j, k;
    mx = -inf;
    memset(fact, 0, sizeof(fact));
    for (i = 0; i < arr.size(); i++) factor(arr[i]);
    sum = 1;
    for (i = 2; i <= mx; i++)
        if (fact[i]) sum = (sum * bigmod(i, fact[i])) % 1000000007;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);  // cin.tie(0);
    int t, tc;
    cin >> tc;
    int cnt = 0, sum = 0;
    int i, j, k, l, n, m;
    sieve(345);  // Sieve
    while (tc--) {
        cin >> n;
        arr.clear();
        for (i = 1; i <= n; i++) cin >> k, arr.push_back(k);
        sum = LCM();
        printf("%d\n", sum);
    }
    return 0;
}

/*
Input:

4

5
1 2 3 4 5
6
1 2 3 4 5 6
7
1 2 3 4 5 6 7
5
7 11 13 19 21

Output:
60
60
420
57057

*/
