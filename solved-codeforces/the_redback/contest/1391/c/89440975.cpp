/***
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://maruftuhin.com
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ft        first
#define sd        second
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define eps       1e-9

const ll inf = 1e9;
const ll mod = 1e9 + 7;
const ll NN = 1e6 + 10;

// debugging macros
#ifdef redback
#include "prettyprint.hpp"
#else
#define dbg(args...)
#endif
ll f[NN];

void fact(ll n) {
    f[0] = 1;
    for (ll i = 1; i < n; i++) f[i] = (i * f[i - 1]) % mod;
}

int my_pow(int a, int b) {
    int r = 1;
    while (b) {
        if (b % 2) r = (long long)r * a % mod;
        b /= 2;
        a = (long long)a * a % mod;
    }
    return r;
}

void solve(ll n) {
    ll i, j, k;
    ll m, ans = 0;

    for (i = 1; i < n; i++) {
        ll rest = n - i;
        ll tmp = (f[rest] * (rest - 1)) % mod;

        rest = my_pow(2, i - 1);
        tmp = (tmp * rest) % mod;
        ans = (ans + tmp) % mod;
    }

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact(NN);

    ll n;
    cin >> n;
    solve(n);
    return 0;
}
