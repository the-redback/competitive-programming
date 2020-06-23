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
int v[100010];

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n;

    string str;
    mem(v, 0);
    cin >> str;

    ll last = -1;
    ll fl = 0;
    dbg(last, str, v[0]);
    for (i = 0; i < n; i++) {
        if (str[i] == '1')
            for (j = i + 1; j < n; j++) {
                if (str[j] == '0') {
                    v[j] = -2;
                    last = j;
                }
                fl = 1;
            }
        if (fl)
            break;
    }

    dbg(last, str, v[0]);
    if (last != -1)
        v[last] = 0;

    fl = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '0') {
            dbg(str[i]);
            for (int j = i - 1; j >= 0; j--) {
                if (str[j] == '1') {
                    v[j] = -1;
                }
            }
            fl = 1;
        }
        if (fl)
            break;
    }
    dbg(last, str, v[0]);

    string ans = "";
    for (i = 0; i < n; i++) {
        dbg(i, v[i]);
        if (v[i] == 0) {
            ans += str[i];
        }
    }

    cout << ans << "\n";
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
