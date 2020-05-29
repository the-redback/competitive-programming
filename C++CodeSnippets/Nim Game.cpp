/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include <bits/stdc++.h>
using namespace std;

#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define NN        1050

main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    int k, l, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        int res = 0;
        while (n--) {
            cin >> k;
            res ^= k;
        }
        if (res)
            printf("Case %d: Alice\n", t++);   // First move
        else
            printf("Case %d: Bob\n", t++);
    }
    return 0;
}
