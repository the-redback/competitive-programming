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

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n >> m;
    ll cnt = 0;
    vector<ll> row(60);
    vector<ll> col(60);
    vector<vector<ll>> a(60, vector<ll>(60, 0));
    // or, ll a[60][60]={0};

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> k;
            row[i] += k;
            col[j] += k;
            a[i][j] = k;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 0 && row[i] == 0 && col[j] == 0) {
                cnt++;
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    dbg(cnt);

    if (cnt % 2 == 0) {
        cout << "Vivek\n";
    } else {
        cout << "Ashish\n";
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
