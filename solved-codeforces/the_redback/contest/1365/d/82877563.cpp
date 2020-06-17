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
char a[60][60];
bool vis[60][60];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
ll R, C;

void rec(ll i, ll j) {
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++) {
        ll x = i + dx[k];
        ll y = j + dy[k];
        if (x < 0 || y < 0 || x >= R || y >= C || a[x][y] == '#' || vis[x][y]) {
            continue;
        }
        rec(x, y);
    }
    return;
}

void chk(ll r, ll c) {
    for (int k = 0; k < 4; k++) {
        ll x = r + dx[k];
        ll y = c + dy[k];
        if (x < 0 || y < 0 || x >= R || y >= C) {
            continue;
        }
        if (a[x][y] == '.') {
            a[x][y] = '#';
        }
    }
}

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n >> m;
    R = n;
    C = m;

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                chk(i, j);
            }
        }
    }

    mem(vis, 0);
    if (a[n - 1][m - 1] != '#') {
        rec(n - 1, m - 1);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 'G' && vis[i][j] != 1) {
                cout << "No\n";
                return;
            } else if (a[i][j] == 'B' && vis[i][j] == 1) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
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
