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

vector<ll> a(NN), b(NN);
vector<ll> vis(NN), min(NN), ar, sec(NN), srt;

void rec(ll u, ll carry) {
    dbg(u, carry) vis[u] = 1;
    ll fl = 0;
    if (a[u] + carry < 0) {
        fl = 1;
        sec.pb(u);
        dbg(u);
    }

    if (b[u] == -1) {
        srt.pb(u);
        return;
    }

    rec(b[u], fl == 0 ? carry + a[u] : 0);
    srt.pb(u);
    return;
}

void solve(ll n) {
    ll i, j, k;
    ll m, ans = 0;
    srt.clear();
    ar.clear();
    sec.clear();

    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 1; i <= n; i++) {
        cin >> b[i];
        sec[i] = 0;
        vis[i] = 0;
    }

    for (i = 1; i <= n; i++) {
        if (vis[i]) continue;
        rec(i, 0);
    }

    reverse(all(srt));
    dbg(srt);
    dbg(sec);

    for (i = 1; i <= n; i++) vis[i] = 0;

    for (auto u : srt) {
        if (vis[u] || a[i] < 0) continue;
        ll v = u;
        dbg(v, u);
        while (!vis[v]) {
            dbg(v, a[v], b[v]);
            vis[v] = 1;
            ans += a[v];
            ar.pb(v);
            if (b[v] == -1) {
                break;
            }
            a[b[v]] += a[v];
        }
    }
    for (auto val : sec) ans += -1 * a[val];

    cout << ans << "\n";
    for (auto val : ar) {
        cout << val << " ";
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    solve(n);
    return 0;
}
