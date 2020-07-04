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
vector<ll> b, p;
ll a;

ll check(ll n) {
    ll sum = 0;
    for (ll i = n, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
        sum += max(0ll, p[i] - b[j]);
    }
    return a >= sum;
}

void solve(ll n) {
    ll i, j, k;
    ll m;
    cin >> m >> a;
    for (i = 0; i < n; i++) {
        cin >> k;
        b.pb(k);
    }
    for (i = 0; i < m; i++) {
        cin >> k;
        p.pb(k);
    }

    sort(all(b));
    sort(all(p));

    ll low = 0, high = min(n - 1, m - 1);
    ll mx = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;

        if (check(mid)) {
            mx = max(mx, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    ll sum = 0;
    for (i = 0; i <= mx; i++) {
        sum += p[i];
    }

    ll rem = max(sum - a, 0ll);

    cout << mx + 1 << " " << rem << "\n";
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
