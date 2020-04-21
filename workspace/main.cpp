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
#define NN        100010

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

ll leng(ll x, ll y) {
    ll sum = 1;
    ll len = 1;
    ll l   = abs(x) + abs(y);

    for (ll i = 1; sum < l;) {
        i *= 2;
        sum += i;
        len++;
    }
    debug(len, sum) return len;
}

string str;

bool rec(int x, int y, int len) {
    debug(x, y, len) debug(1 << len) if (x == 0 && y == 0) {
        if (len != 0) return false;
        return true;
    }
    if (len == 0) {
        return false;
    }
    ll xx = x, yy = y;
    if (abs(x) > abs(y)) {
        if (x > 0) {
            str += 'E';
            xx -= 1 << len - 1;
        } else {
            str += 'W';
            xx += 1 << len - 1;
        }
    } else {
        if (y > 0) {
            str += 'N';
            yy -= 1 << len - 1;
        } else {
            str += 'S';
            yy += 1 << len - 1;
        }
    }
    return rec(xx, yy, len - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        ll i, j, k, l;   // v
        ll x, y;         // b
        cin >> x >> y;   // a

        str       = "";
        ll   len  = leng(x, y);
        bool poss = rec(x, y, len);

        if (!poss) {
            printf("Case #%d: IMPOSSIBLE\n", t++);
            continue;
        }

        printf("Case #%d: ", t++);
        reverse(str.begin(), str.end());
        printf("%s\n", str.c_str());
    }
    return 0;
}
