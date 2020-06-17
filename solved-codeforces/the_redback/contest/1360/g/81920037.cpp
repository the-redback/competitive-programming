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
#define xx        first
#define yy        second
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        100010

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

ll arr[100][100];

void solve() {
    ll i, j, k;
    ll n, m;
    ll a, b;
    cin >> n >> m >> a >> b;

    if (n * a != m * b) {
        cout << "NO\n";
        return;
    }

    vector<ll> col(m), row(n);
    mem(arr, 0);

    ll hand = 0;

    for (hand = 1; hand < m; hand++) {
        if (n * hand % m == 0) {
            break;
        }
    }

    for (ll i = 0, dx = 0; i < n; i++, dx += hand) {
        for (j = 0; j < m; j++) {
            k = (j + dx) % m;
            if (col[k] < b && row[i] < a && arr[i][k] == 0) {
                arr[i][k] = 1;
                col[k]++;
                row[i]++;
            }
        }
    }

    cout << "YES\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

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
