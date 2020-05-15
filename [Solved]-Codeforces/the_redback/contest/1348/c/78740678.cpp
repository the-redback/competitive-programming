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

string str, ans;

bool poss(ll k) {
    ll i, j;
    ll fl=0;
    for (i = k - 1; i < str.size(); i += k) {
        j = i - k + 1;
        ans += str[i];
        if (str[i] != str[j]) {
            return false;
        }
    }
    

    return true;
}

void solve(ll tc) {
    ll i, j, k, n;
    cin >> n >> k;
    cin >> str;
    sort(str.begin(), str.end());

    ans   = "";
    ll fl = 0;
    for (i = 1; i < str.size(); i++) {
        if (str[i] != str[i - 1]) {
            fl = 1;
            break;
        }
    }

    if (fl == 0) {
        ll ret = ceil(n / (1.0 * k));
        for (i = 0; i < ret; i++) {
            cout << str[i];
        }
        cout << "\n";
        return;
    }

    if (str[k - 1] != str[0]) {
        cout << str[k - 1] << "\n";
        return;
    }

    string ans2 = "";
    ans2 += str[k - 1];
    for (i = k; i < str.size(); i++) {
        ans2 += str[i];
    }

    string ans3 = ans2;

    ll   ret = ceil(n / (1.0 * k));
    bool pos = poss(k);
    if ((ret * k) == n && pos) {
        if (ans3 > ans) {
            ans3 = ans;
        }
    } else if (pos){
        ans+=str[n-1];
        if (ans3 > ans) {
            ans3 = ans;
        }
    }

    cout << ans3 << "\n";
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
