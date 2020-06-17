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
const ll NN = 1e7;

bool p[NN + 7];   // Hashing
int pr[NN + 7];   // storing prime

void sieve(ll n) {
    ll i, j, k, l;
    p[1] = 1;
    for (i = 4; i <= n; i += 2) {
        p[i] = 1;
        pr[i] = 2;
    }
    for (i = 3; i <= n; i += 2) {
        if (p[i] == 0) {
            for (j = i + i; j <= n; j += i) {
                p[j] = 1;
                pr[j] = i;
            }
        }
    }
}

ll a[500010], b[500010];

void solve(ll n) {
    ll i, j, k;
    ll m;
    for (i = 0; i < n; i++) {
        cin >> k;
        dbg(k, pr[k]);
        if (pr[k] == 0) {
            a[i] = -1;
            b[i] = -1;
            continue;
        }
        j = k / pr[k];
        dbg(k, pr[k], j);
        if (__gcd(j + pr[k], k) == 1) {
            a[i] = pr[k];
            b[i] = j;
            continue;
        }
        while (j % pr[k] == 0) {
            j /= pr[k];
        }
        if ( j> 1 && __gcd(j + pr[k], k) == 1) {
            a[i] = pr[k];
            b[i] = j;
            continue;
        } else {
            a[i] = -1;
            b[i] = -1;
            continue;
        }
    }

    for (i = 0; i < n; i++) {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout << "\n";
    for (i = 0; i < n; i++) {
        if (i)
            cout << " ";
        cout << b[i];
    }
    cout << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(NN);
    dbg(pr, 100) ll t = 1, tc;
    // cin >> tc;
    ll n, m;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}
