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

void solve() {
    ll i, j, k;
    ll n, m;
    ll x, y;
    cin >> n >> x >> y;

    vector<ll> v[n+2], ans(n), vis(n+2), a(n);
    priority_queue<pair<int, int>> pq;

    for (i = 0; i < n; i++) {
        cin >> k;
        a[i] = k;
        v[k].pb(i);
        vis[k]++;
    }
    ll in = 0, sum = n;
    for (i = 1; i <= n + 1; i++) {
        if (vis[i] > 0) {
            pq.push({vis[i], i});
        }
        if (vis[i] == 0) {
            in = i;
        }
    }

    k = y - x;

    while (x > 0 && pq.size()) {
        pair<ll, ll> pi;
        pi = pq.top();
        pq.pop();

        ll ii = v[pi.second].back();
        v[pi.second].pop_back();
        sum--;

        ans[ii] = pi.second;
        pi.first--;
        if (pi.first > 0) pq.push(pi);
        x--;
    }

    while (pq.size() >= 2 && k > 0) {
        if (k == 3 && pq.size() == 3 && sum == 3) break;
        pair<ll, ll> pi, pj;
        pi = pq.top();
        pq.pop();
        pj = pq.top();
        pq.pop();

        ll ii = v[pi.second].back();
        ll jj = v[pj.second].back();
        v[pi.second].pop_back();
        v[pj.second].pop_back();
        sum -= 2;

        ans[ii] = a[jj];
        k--;
        if (k > 0) {
            ans[jj] = a[ii];
            k--;
        }
        pi.first--;
        pj.first--;
        if (pi.first > 0) pq.push(pi);
        if (pj.first > 0) pq.push(pj);
    }

    if (k == 3) {
        vector<pair<ll, ll>> s;
        for (i = 0; i <= n + 1 && s.size() < 3; i++) {
            if (v[i].size()) {
                s.emplace_back(i, v[i].back());
                v[i].pop_back();
            }
        }
        if (s.size() < 3) {
            cout << "NO\n";
            return;
        }
        ans[s[2].second] = s[0].first;
        ans[s[1].second] = s[2].first;
        ans[s[0].second] = s[1].first;
        k -= 3;
    }

    if (k > 0 || x > 0) {
        cout << "NO\n";
        return;
    }

    for (i = 0; i < n; i++) {
        if (ans[i] == 0) ans[i] = in;
    }

    cout << "YES\n";
    for (i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

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
