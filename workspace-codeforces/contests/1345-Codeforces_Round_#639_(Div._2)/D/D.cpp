/***
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://maruftuhin.com
 */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        200010

// clang-format off
#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros
// clang-format on

char a[1010][1010];
ll   row[1010], col[1010];
ll   r, c;

int  dx[] = {-1, 0, 0, 1};
int  dy[] = {0, -1, 1, 0};
void rec(ll i, ll j) {
    if (i < 0 || j < 0 || i >= r || j >= c) {
        return;
    }
    if (a[i][j] != '#') {
        return;
    }

    a[i][j] = '*';
    for (int k = 0; k < 4; k++) {
        rec(i + dx[k], j + dy[k]);
    }
    return;
}

void solve(ll n, ll m) {
    ll i, j, k;
    // cin >> n >> m;
    r = n;
    c = m;
    string str;
    ll     total = 0, fl1 = 0, fl2 = 0;
    for (i = 0; i < n; i++) {
        cin >> str;
        for (j = 0; j < m; j++) {
            a[i][j] = str[j];
            if (a[i][j] == '#') {
                total++;
            }
        }
    }

    if (total == 0) {
        cout << "0\n";
        return;
    }

    for (i = 0; i < n; i++) {
        ll sum = 0;
        if (a[i][0] == '#') {
            sum = 1;
        }
        for (j = 1; j < m; j++) {
            if (a[i][j] != a[i][j - 1] && a[i][j] == '#') {
                sum++;
            }
        }
        if (sum > 1) {
            cout << "-1\n";
            return;
        }
        if (sum == 0) {
            fl1 = 1;
        }
    }

    for (j = 0; j < m; j++) {
        ll sum = 0;
        if (a[0][j] == '#') {
            sum = 1;
        }
        for (i = 1; i < n; i++) {
            if (a[i][j] != a[i - 1][j] && a[i][j] == '#') {
                sum++;
            }
        }
        if (sum > 1) {
            cout << "-1\n";
            return;
        }
        if (sum == 0) {
            fl2 = 1;
        }
    }

    if (fl2 || fl1) {
        if (!fl1 || !fl2) {
            cout << "-1\n";
            return;
        }
    }

    ll sum = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                rec(i, j);
                sum++;
            }
        }
    }

    cout << sum << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
    return 0;
}
