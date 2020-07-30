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
const ll NN = 1e5 + 10;

// debugging macros
#ifdef redback
#include "prettyprint.hpp"
#else
#define dbg(args...)
#endif

ll a[111];
ll N, K, L;
ll p[211];
ll dp[111][211];

ll rec(ll pos, ll t) {
    if (pos == N) return 1;
    if (a[pos] + p[t % (K + K)] > L) return 0;

    ll& tc = dp[pos][t];
    if (tc != -1) {
        return tc;
    }

    tc = 0;

    for (ll i = 1; i <= K + K; i++) {
        tc |= rec(pos + 1, (t + i) % (K + K));
        if (tc) return tc;

        if (a[pos] + p[(t + i) % (K + K)] > L) {
            return tc;
        }
    }
    return tc;
}

void solve() {
    ll i, j, k;
    ll n, m, ans = 0;
    cin >> N >> K >> L;
    mem(dp, -1);
    for (i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (i = 0; i <= K; i++) {
        p[i] = i;
    }
    for (j = K + 1, i = K - 1; i > 0; i--, j++) {
        p[j] = i;
    }

    dbg(p, K + K);

    for (i = 1; i <= K + K; i++) {
        if (rec(0, i)) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
