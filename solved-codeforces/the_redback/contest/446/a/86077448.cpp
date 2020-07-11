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

void solve(ll n) {
    ll i, j, k;
    ll m;
    vector<ll> v(n), left(n), right(n);
    for (i = 0; i < n; ++i) {
        cin >> v[i];
    }
    left[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i] > v[i - 1]) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 1;
        }
    }
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 1;
        }
    }

    ll ans = max(left[0], right[0]);
    ans = max(ans, max(left[n - 1], right[n - 1]));
    for (i = 1; i < n - 1; i++) {
        ans = max(ans, max(left[i], right[i]) + 1);
        if (v[i - 1] + 1 < v[i + 1]) {
            ans = max(ans, left[i - 1] + right[i + 1] + 1);
        }
    }
    if (n <= 2) ans = n;

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
