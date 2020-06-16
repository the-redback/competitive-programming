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
    string str;
    cin >> str;
    string ans;
    cin >> n;
    vector<ll> v(n);
    for (i = 0; i < n; i++) {
        cin >> v[i];
        ans += " ";
    }

    sort(all(str));

    for (i = 0; i < n; i++) {
        ll cnt = 0;
        ll mn = inf;
        for (j = 0; j < n; j++) {
            if (v[j] < mn) {
                cnt = 1;
                mn = v[j];
            } else if (v[j] == mn)
                cnt++;
        }

        if (mn == inf)
            break;

        ll in;
        for (int j = str.size() - 1; j - cnt + 1 >= 0; j--)
            if (str[j] == str[j - cnt + 1]) {
                in = j;
                break;
            }

        vector<ll> vv;
        for (j = 0; j < n; j++)
            if (v[j] == mn) {
                ans[j] = str[in];
                vv.pb(j);
            }

        for (auto j : vv) {
            v[j] = inf;
            for (k = 0; k < n; k++) {
                if (v[k] == inf)
                    continue;
                v[k] -= abs(j - k);
            }
        }

        string s = "";
        for (int j = in - 1; j >= 0; j--)
            if (str[j] != str[in]) {
                in = j;
                break;
            }

        for (j = 0; j <= in; j++) s += str[j];

        str = s;
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
