
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

int tt[200010];

void solve(ll n) {
    ll i, j, k;
    ll m;
    cin >> k;
    vector<ll> both, alice, bob, ans;
    ll a, b;

    for (i = 0; i < n; i++) {
        cin >> tt[i] >> a >> b;

        if (a && a == b) {
            both.pb(tt[i]);
        } else if (a == 0 && b == 1) {
            bob.pb(tt[i]);
        } else if (a == 1 && b == 0) {
            alice.pb(tt[i]);
        }
    }

    sort(allr(alice));
    sort(allr(bob));

    if ((int)both.size() + (int)alice.size() < k ||
        (int)both.size() + (int)bob.size() < k) {
        cout << "-1\n";
        return;
    }

    while (!alice.empty() && !bob.empty()) {
        both.pb(alice.back() + bob.back());
        alice.pop_back();
        bob.pop_back();
    }

    sort(all(both));

    ll sum = 0;

    for (i = 0; i < k; i++) {
        sum += both[i];
    }

    cout << sum << "\n";
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
