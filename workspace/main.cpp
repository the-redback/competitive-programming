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

typedef long long   ll;
#define mem(a, b)   memset(a,b,sizeof(a))
#define inf         1e9
#define eps         1e-9
#define mod         1000000007
#define NN          100010


#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros


int main() {
// #ifdef redback
//     freopen("input.in", "r", stdin);
//     freopen("output.in", "w", stdout);
// #endif
    ll t = 1, tc;
    cin>> tc ;
    ll n, m;
    while ( tc--) {
        string str;
        cin >> str;

        ll order = 0;
        string ans = "";
        int j = 0;

        for (int i = 0; i < str.size(); ++i) 
        {
            int k = str[i] - '0';
            if (order == k) {
                ans += str[i];
            } else if ( order < k) {
                while (order < k) {
                    ans += '(';
                    order++;
                }
                ans += str[i];
            }  else if ( order > k) {
                while (order > k) {
                    ans += ')';
                    order--;
                }
                ans += str[i];
            }
        }

        while (order > 0) {
            ans += ')';
            order--;
        }
        printf("Case #%d: %s\n", t++, ans.c_str());
    }
    return 0;
}
