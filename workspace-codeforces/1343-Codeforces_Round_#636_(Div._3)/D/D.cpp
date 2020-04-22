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
#define NN        600010

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

ll a[NN];
ll K;

ll rec(ll n, ll x) {
    ll cnt = 0;
    for (int i = 0; i < n / 2; i++) {
        ll k = a[i] + a[n - i - 1];
        if (k == x) {
            continue;
        }
        if (x > k) {
            if (x - k <= K - a[i] || x - k <= K - a[n - 1 - i]) {
                cnt++;
            } else {
                cnt += 2;
            }
        } else {
            if (k - x <= a[i] - 1 || k - x <= a[n - 1 - i] - 1) {
                cnt++;
            } else {
                cnt += 2;
            }
        }
    }
    debug(n,x,cnt)
    return cnt;
}

ll ternary_search(ll n) {
    int low = 1, high = K+K;
    int midleft, midright;

    ll cnt = inf;
    while (high - low > 3) {
        midleft = low + (high - low) / 3 ;
        midright = high - (high - low ) / 3;

        ll cnt1 = rec(n, midleft);
        ll cnt2 = rec(n, midright);
        cnt      = min(cnt, cnt1);
        cnt      = min(cnt, cnt2);

        if ( cnt1 > cnt2 )
            low = midleft ;
        else
            high = midright ;
    }

    for (int i = low; i <= high; i++) {
       cnt      = min(cnt,rec(n, i));
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        cin >> n >> K;
        ll i, j, k;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll ans = ternary_search(n);
        cout << ans << "\n";
    }
    return 0;
}
