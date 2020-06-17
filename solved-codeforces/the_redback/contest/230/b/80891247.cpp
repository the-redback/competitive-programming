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

#define NN 1000010
bool       p[NN + 7];   // Hashing
vector<ll> pr;          // storing prime

void sieve(ll n) {
    ll i, j, k, l;
    p[1] = 1;
    pr.push_back(2 * 2);
    for (i = 4; i <= n; i += 2) p[i] = 1;
    for (i = 3; i <= n; i += 2) {
        if (p[i] == 0) {
            pr.push_back(i * i);
            for (j = i * i; j <= n; j += 2 * i) p[j] = 1;
        }
    }
}

void solve(ll n) {
    ll i, j, k;
    ll m;
    for (i = 0; i < n; i++) {
        cin >> m;

        auto low = lower_bound(pr.begin(), pr.end(), m);
        if (*low == m) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(1000000);

    ll t = 1, tc;
    // cin >> tc;
    ll n, m;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}
