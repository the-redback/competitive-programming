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

/* -------------------------------------------------------------------------- */
/*                              Debugging Macros                              */
/* -------------------------------------------------------------------------- */
#ifdef redback
#include "prettyprint.hpp"
#define dbg(...)                        \
    cout << "L-" << __LINE__ << " :: "; \
    _print_out(#__VA_ARGS__, __VA_ARGS__);
template <typename T>
void _print_out(const char* name, T&& arg1) {
    cout << name << " = " << arg1 << endl;
}
template <typename T1, typename... Args>
void _print_out(const char* names, T1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " = " << arg1 << " | ";
    _print_out(comma + 1, args...);
}
template <typename T>
void _print_out(const char* name, T a[], int n) {
    cout << name << " = " << pretty_print_array(a, n) << endl;
}
#else
#define dbg(args...)
#endif
/* -------------------------------------------------------------------------- */
vector<ll> fr[2020];

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n;
    vector<ll> v(n + n);
    bitset<2020> bit;

    ll mx = 0;
    for (i = 0; i < n + n; i++) {
        cin >> v[i];
        mx = max(v[i], mx);
    }

    for (i = 2; i <= mx + mx; i++) {
        dbg(i);
        for (j = 0; j <= i; j++) {
            fr[j].clear();
        }

        for (j = 0; j < n + n; j++) {
            fr[v[j] % i].pb(j);
        }

        ll sum = (int)fr[0].size() / 2;
        for (j = 1; j < i; j++) {
            dbg(j, i - j, sum, (int)fr[j].size(), (int)fr[i - j].size());
            if (j == i - j) {
                sum += (int)fr[j].size() / 2;
            } else {
                sum += min((int)fr[j].size(), (int)fr[i - j].size());
            }
            dbg(sum);
        }

        dbg(i, sum, n - 1);
        dbg(v);
        if (sum >= n - 1) {
            dbg(i);
            bit.reset();
            for (j = 0; j < n - 1; j++) {
                dbg(j, n);
                for (k = 0; k < i; k++) {
                    ll l = i - k;
                    if (k == 0)
                        l = 0;
                    dbg(k, l);
                    ll v1 = -1, v2 = -1;
                    if (fr[k].size() > 0 && fr[l].size() > 0) {
                        for (auto val : fr[k]) {
                            if (bit[val] == 0) {
                                v1 = val;
                                break;
                            }
                        }

                        for (auto val : fr[l]) {
                            if (bit[val] == 0 && val != v1) {
                                v2 = val;
                                bit[val] = 1;
                                break;
                            }
                        }
                    }
                    if (v1 != -1 && v2 != -1) {
                        bit[v1] = 1;
                        bit[v2] = 1;
                        cout << v1 + 1 << " " << v2 + 1 << "\n";
                        break;
                    }
                }
            }
            break;
        }
    }

    // cout << n << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        solve();
    }
    return 0;
}
