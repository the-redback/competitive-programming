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

const ll inf = 1e8;
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
int v[1010];
int bit[1010];
vector<int> ans;
int in;
int check(int j, int n) {
    int fl = 0, i;
    for (i = j; i < n; i++) {
        bit[i] = 0;
        if (i != j && v[i] < v[i - 1]) fl = 1;
    }
    bit[n] = 0;
    if (fl == 0) return -inf;
    for (i = j; i < n; i++) {
        bit[v[i]]++;
        if (bit[v[i]] > 1) in = i;
    }
    for (i = j; i <= n; i++) {
        if (bit[i] == 0) return i;
    }
    return n;
}

void solve() {
    int i, k;
    int n, m;
    ans.clear();
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }
    dbg(v, n);

    // while (true) {
    //     in = -1;

    //     k = check(0, n);
    //     if (k == -inf || k == n) break;
    //     dbg(k, in);
    //     if (in == -1) in = k;
    //     ans.pb(in + 1);
    //     v[in] = k;
    //     dbg(v, n);
    // }
    ll j = 0, l = n;
    while (true) {
        k = check(j, l);

        if (k == -inf) break;
        dbg(j, l, k);
        if (k == l) {
            ans.pb(l);
            v[l - 1] = k;
            l--;
        } else if (k == j) {
            ans.pb(j + 1);
            v[j] = k;
            j++;
        } else {
            ans.pb(k + 1);
            v[k] = k;
        }
        dbg(v, n);
    }

    cout << (int)ans.size() << "\n";
    for (auto val : ans) {
        cout << val << " ";
    }

    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1, tc;
    cin >> tc;
    int n, m;
    while (tc--) {
        solve();
    }
    return 0;
}
