/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        100010

#define read(a) scanf("%lld", &a)

double dist(ll x, ll y, ll xx, ll yy) { return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy)); }

int main() {
// ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt", "r", stdin);
#endif

    ll t = 1, tc;
    // read(tc);
    double r;
    ll i, j, k, l, x, y, xx, yy, m, n;
    while (cin >> r >> x >> y >> xx >> yy) {
        ll rr = r * 2;
        if (x == xx && y == yy) {
            cout << "0\n";
            continue;
        }
        double dis = dist(x, y, xx, yy);
        ll ans = 1;
        while (dis - rr > 0) dis -= rr, ans++;
        cout << ans << "\n";
    }
    return 0;
}
