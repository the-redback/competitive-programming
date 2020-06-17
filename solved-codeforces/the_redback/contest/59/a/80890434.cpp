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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll     n, m;
    string str;
    while (cin >> str) {
        ll i, j, k;

        ll     l = 0, u = 0;
        string lw, up;

        for (i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                u++;
                up += str[i];
                lw += str[i] - 'A' + 'a';
            } else {
                l++;
                up += str[i] - 'a' + 'A';
                lw += str[i];
            }
        }

        if (u <= l) {
            cout << lw << "\n";
        } else {
            cout << up << "\n";
        }
    }
    return 0;
}
