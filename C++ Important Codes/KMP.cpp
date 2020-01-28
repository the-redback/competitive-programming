/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        1000010

#define read(a)   scanf("%lld",&a)

ll fail[NN];  //Highest Prefix which equals as postfix at i.
char s[NN];   //Main String.
char p[NN];   //Find P-string in main string.

void failure(void) {
    ll i, j, k, l;
    ll m = strlen(p);

    fail[0] = 0;
    ll q = 0;

    for (i = 1; i < m; i++) { //starts from 1, not 0.
        while (q > 0 && p[i] != p[q])
            q = fail[q - 1];

        if (p[i] == p[q])
            q++;
        fail[i] = q;
    }
    return;
}

ll KMP(void) {
    ll i, j, k, l, cnt = 0;
    ll m = strlen(p);
    l = strlen(s);

    failure();
    ll q = 0;

    for (i = 0; i < l; i++) {
        while (q > 0 && s[i] != p[q])
            q = fail[q - 1];

        if (s[i] == p[q])
            q++;
        if (q == m) {
            q = fail[q - 1];
            cnt++; //we got one substring
        }
    }
    return cnt;
}


main() {
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt", "r", stdin);
#endif

    ll t = 1, tc;
    read(tc);
    ll i, j, k, l, m, n;
    while (tc--) {
        scanf("%s", &s);
        scanf("%s", &p);
        ll ans = KMP();
        printf("Case %lld: %lld\n", t++, ans);

    }
    return 0;
}

