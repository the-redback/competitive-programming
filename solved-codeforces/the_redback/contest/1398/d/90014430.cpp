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

ll dp[222][222][222];
ll R, G, B;
vector<ll> r, g, b;

ll rec(ll rr, ll gg, ll bb) {
    ll tmp = 0;
    if (rr >= R) tmp++;
    if (gg >= G) tmp++;
    if (bb >= B) tmp++;

    if (tmp >= 2) return 0;

    ll& tc = dp[rr][gg][bb];
    if (tc != -1) return tc;

    if (rr < R) tc = rec(rr + 1, gg, bb);
    if (gg < G) tc = max(tc, rec(rr, gg + 1, bb));
    if (bb < B) tc = max(tc, rec(rr, gg, bb + 1));

    if (rr < R && gg < G) tc = max(tc, rec(rr + 1, gg + 1, bb) + r[rr] * g[gg]);
    if (rr < R && bb < B) tc = max(tc, rec(rr + 1, gg, bb + 1) + r[rr] * b[bb]);
    if (gg < G && bb < B) tc = max(tc, rec(rr, gg + 1, bb + 1) + g[gg] * b[bb]);

    return tc;
}

void solve(ll n) {
    ll i, j, k;
    ll m, ans = 0;
    R = n;
    cin >> G >> B;
    r.resize(R);
    g.resize(G);
    b.resize(B);
    for (i = 0; i < R; i++) cin >> r[i];
    for (i = 0; i < G; i++) cin >> g[i];
    for (i = 0; i < B; i++) cin >> b[i];

    sort(allr(r));
    sort(allr(g));
    sort(allr(b));

    mem(dp, -1);

    ans = rec(0, 0, 0);

    cout << ans << "\n";
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
