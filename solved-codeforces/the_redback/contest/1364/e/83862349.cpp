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
    ll x = 1, y = 2;
    cout << "? " << x << " " << y << "\n";
    cout.flush();

    ll prev;
    cin >> prev;
    if (prev == -1) {
        return;
    }

    for (i = 3; i <= n; i++) {
        ll z = i;
        cout << "? " << y << " " << z << "\n";
        cout.flush();

        ll sec;
        cin >> sec;
        if (sec == -1) {
            return;
        }

        if (sec < prev) {
            x = z;
            prev = sec;
        } else if (sec > prev) {
            // z is no good. keep previous x and y;
            continue;
        } else {
            // throw y away. It can't be zero.
            y = z;
            cout << "? " << x << " " << y << "\n";
            cout.flush();

            cin >> prev;
            if (prev == -1) {
                return;
            }
        }
    }

    ll sec = prev;
    while (sec == prev) {
        k = 1 + rand() % n;
        if (k == x || k == y)
            continue;
        cout << "? " << x << " " << k << "\n";
        cout.flush();

        cin >> prev;
        if (prev == -1) {
            return;
        }

        cout << "? " << y << " " << k << "\n";
        cout.flush();

        cin >> sec;
        if (sec == -1) {
            return;
        }
    }

    ll z;
    if (sec < prev) {
        z = y;
    } else {
        z = x;
    }

    vector<ll> v(n + 1);

    for (i = 1; i <= n; i++) {
        if (i == z)
            continue;
        cout << "? " << z << " " << i << "\n";
        cout.flush();

        cin >> v[i];
        if (v[i] == -1) {
            return;
        }
    }
    v[z] = 0;

    cout << "!";

    for (i = 1; i <= n; i++) {
        cout << " " << v[i];
    }

    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0);

    ll n;
    cin >> n;
    solve(n);
    return 0;
}
