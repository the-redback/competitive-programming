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

void solve(ll t) {
    ll i, j, k;
    ll n, m;
    cin >> n;

    vector<string> str(n);
    for (i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (str[i][j] == '1' && i != n - 1 && j != n - 1 &&
                str[i][j + 1] != '1' && str[i + 1][j] != '1') {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        solve(t++);
    }
    return 0;
}
