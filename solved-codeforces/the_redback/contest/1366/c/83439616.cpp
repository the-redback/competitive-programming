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

ll dp[35][35][35][35];

ll a[35][35];

// void rec(ll i,ll j,ll r,ll c){
//     if(i>r || j>c){
//         return;
//     }

//     ll &tc=dp[i][j][r][c];

//     if(tc != 0){
//         return;
//     }

//     tc=1;

//     if(dp[])

//     if(i+1 <= r){

//     }

// }

// ll check(ll on1, ll on2, ll zr1, ll zr2) {
//     ll
// }

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    ll sum = 0;
    ll r, c;

    for (i = 0; i < (n + m - 1) / 2; i++) {
        ll on1 = 0, on2 = 0, zr1 = 0, zr2 = 0;
        dbg("--------------", i);
        for (r = min(i, n - 1), c = max(i - n + 1, 0ll); r >= 0 && c < m;
             r--, c++) {
            dbg(r, c, n - 1 - r, m - 1 - c);
            dbg(a[r][c], a[n - 1 - r][m - 1 - c]);
            if (a[r][c] == 1) {
                on1++;
            } else {
                zr1++;
            }

            if (a[n - 1 - r][m - 1 - c] == 1) {
                on2++;
            } else {
                zr2++;
            }
        }
        sum += min(on1 + on2, zr1 + zr2);
    }

    // if ((n + m - 1) % 2 == 1) {
    //     ll on1 = 0, on2 = 0, zr1 = 0, zr2 = 0;
    //     for (r = n / 2, c = m / 2; r >= 0 && c >= 0; r--, c--) {
    //         dbg(r, c, n - 1 - r, m - 1 - c);
    //         dbg(a[r][c], a[n - 1 - r][m - 1 - c]);
    //         if (a[r][c] != a[n - r - 1][m - c - 1]) {
    //             sum++;
    //         }
    //     }
    // }

    cout << sum << "\n";
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
