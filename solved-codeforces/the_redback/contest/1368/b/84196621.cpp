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
ll pow(ll n, ll k) {
    ll sum = 1;
    while (k > 0) {
        sum *= n;
        k--;
    }
    return sum;
}

void solve(ll n) {
    ll i, j, k;
    ll m;
    cin >> n;

    string str = "codeforces";
    vector<ll> v(10);
    ll pw = 0;

    for (i = 0; i <= 40; i++) {
        if (pow(i, 10) > n) {
            dbg(n, pow(i, 10));
            pw = i;
            break;
        }
    }
    dbg(pw);

    for (i = 0; i < v.size(); i++) {
        v[i] = pw - 1;
    }
    dbg(v);

    ll cnt = pow(pw - 1, 10);

    for (i = 0; i < v.size(); i++) {
        if (cnt >= n)
            break;
        cnt /= pw - 1;
        cnt *= pw;
        v[i] = pw;
    }

    dbg(v);
    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < v[i]; j++) {
            cout << str[i];
        }
    }

    cout << "\n";
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
