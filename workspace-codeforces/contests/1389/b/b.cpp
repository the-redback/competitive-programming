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
vector<ll> v(NN), sum(NN);

void solve() {
    ll i, j, k, z;
    ll n, m, ans = 0;
    cin >> n >> k >> z;
    v.resize(n);
    sum.resize(n);

    ll mx = 0, mx2 = 0;
    ll inx = 0, inx2 = 0;

    cin >> v[0];
    sum[0] = v[0];
    for (i = 1; i < n; i++) {
        cin >> v[i];
        sum[i] = v[i] + sum[i - 1];
    }

    ans = sum[k];
    dbg(ans, n, k, z);

    //     10 7 3
    // 4 6 8 2 9 9 7 4 10 9

    for (i = 1; i <= k; i++) {
        ll tmp = sum[i];
        ll rem = k - i;
        if (z <= 0 || rem <= 0) continue;

        ll d = min((ll)ceil(rem / 2.0), z);

        ll cnt = 0;
        cnt = d + d - 1;
        tmp += v[i - 1] * d;
        tmp += v[i] * (d - 1);
        if (d * 2 <= rem) {
            cnt++;
            tmp += v[i];
        }

        rem = k - i - cnt;
        tmp += sum[i + rem] - sum[i];
        ans = max(ans, tmp);
    }

    cout << ans << "\n";
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
