/***
 *     ███▄ ▄███▓ ▄▄▄       ██▀███   █    ██   █████▒
 *    ▓██▒▀█▀ ██▒▒████▄    ▓██ ▒ ██▒ ██  ▓██▒▓██   ▒
 *    ▓██    ▓██░▒██  ▀█▄  ▓██ ░▄█ ▒▓██  ▒██░▒████ ░
 *    ▒██    ▒██ ░██▄▄▄▄██ ▒██▀▀█▄  ▓▓█  ░██░░▓█▒  ░
 *    ▒██▒   ░██▒ ▓█   ▓██▒░██▓ ▒██▒▒▒█████▓ ░▒█░
 *    ░ ▒░   ░  ░ ▒▒   ▓▒█░░ ▒▓ ░▒▓░░▒▓▒ ▒ ▒  ▒ ░
 *    ░  ░      ░  ▒   ▒▒ ░  ░▒ ░ ▒░░░▒░ ░ ░  ░
 *    ░      ░     ░   ▒     ░░   ░  ░░░ ░ ░  ░ ░
 *           ░         ░  ░   ░        ░
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
    ll n, m, ans = 0;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    ll sum = 0;
    for (i = 0; i < n; i++) {
        if (s1[i] != s2[i]) sum++;
        if (s1[i] > s2[i]) {
            cout << "-1\n";
            return;
        }
    }

    for (ll c = 'a'; c <= 't'; c++) {
        vector<ll> v;
        ll low = 'z';
        for (i = 0; i < n; i++) {
            if (s1[i] == c && s1[i] != s2[i]) {
                v.pb(i);
                low = min(low, (ll)s2[i]);
            }
        }

        for (i = 0; i < v.size(); i++) {
            s1[v[i]] = low;
        }
        if (!v.empty()) ans++;
    }

    cout << min(sum, ans) << "\n";
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
