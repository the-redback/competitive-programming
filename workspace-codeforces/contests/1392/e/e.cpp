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

ll a[26][26];
ll N;
vector<ll> v;

void init() {
    ll hand = 0;
    ll sum = 0;
    ll k = 0;
    ll M = N;
    for (ll l = N - 1; l >= 0; l--) {
        if (l != N - 1) {
            ll oldk = k;
            k = hand + sum + 1;
            hand += oldk;
            sum = 0;
        }

        for (ll i = l, j = 0; i >= 0 && j < N; i--, j++) {
            dbg(i, j);
            a[i][j] = k;
            a[N - 1 - j][N - 1 - i] = k;
            sum += k;
            dbg(sum);
        }
    }
    return;
}

void rec(ll r, ll c, ll sum) {
    if (r >= N - 1 && c >= N - 1) {
        v.pb(sum + a[r][c]);
        return;
    }

    if (r >= N) return;
    if (c >= N) return;

    rec(r + 1, c, sum + a[r][c]);
    rec(r, c + 1, sum + a[r][c]);
    return;
}

void solve() {
    ll i, j, k;
    ll n, m, ans = 0;
    cin >> n;

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    N = 25;
    mem(a, -1);
    init();
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    dbg(a[0][0]);

    // rec(0, 0, 0);
    dbg(v.size());
    sort(all(v));
    for (ll i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1]) cout << "YES" << v[i] << "\n";
    }

    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
