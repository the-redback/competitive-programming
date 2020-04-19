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

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       10007
#define NN        30100


/*
    f(n)= a*f(n-1) + b*f(n-3) +c, if(n > 2)
        = 0                      if(n <= 2)

    f(n+1)= a*f(n) + 0*f(n-1)+ b*f(n-2) +c

   |a 0 b 1|^k * |f(2)| = |f(k+2)|
   |1 0 0 0|     |f(1)|   |f(k+1)|
   |0 1 0 0|     |f(0)|   | f(k) |
   |0 0 0 1|     | c  |   |  c   |
   here,
   a = aa;
   b = bb;
   c = cc;
*/

ll m[5][5];

void mult(ll a[5][5], ll b[5][5]) {
    ll temp[5][5];
    int i, j, k;
    mem(temp, 0);
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            for (k = 0; k < 4; k++)
                temp[i][j] += a[i][k] * b[k][j];
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            a[i][j] = temp[i][j] % mod;
    return;
}

void BigMat(ll a[5][5], int pos) {
    int i, j, k;
    if (pos == 1)
        return;
    if (pos % 2 == 1) {
        BigMat(a, pos - 1);
        mult(a, m);
    } else {
        BigMat(a, pos / 2);
        mult(a, a);
    }
    return;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc;
    cin >> tc;
    ll i, j, k, l, n;
    ll aa, bb, cc;
    while (tc--) {
        cin >> n >> aa >> bb >> cc;
        if (n <= 2) {
            printf("Case %d: 0\n", t++);
            continue;
        }

        ll a[5][5];
        a[0][0] = m[0][0] = aa, a[0][1] = m[0][1] = 0, a[0][2] = m[0][2] = bb, a[0][3] = m[0][3] = 1;
        a[1][0] = m[1][0] = 1,  a[1][1] = m[1][1] = 0, a[1][2] = m[1][2] = 0,  a[1][3] = m[1][3] = 0;
        a[2][0] = m[2][0] = 0,  a[2][1] = m[2][1] = 1, a[2][2] = m[2][2] = 0,  a[2][3] = m[2][3] = 0;
        a[3][0] = m[3][0] = 0,  a[3][1] = m[3][1] = 0, a[3][2] = m[3][2] = 0,  a[3][3] = m[3][3] = 1;


        BigMat(a, n);

        ll b[5][2];

        b[0][0] = 0, b[1][0] = 0, b[2][0] = 0, b[3][0] = cc;

        ll temp[5][5];

        mem(temp, 0);
        for (i = 0; i < 4; i++)
            for (j = 0; j < 1; j++)
                for (k = 0; k < 4; k++)
                    temp[i][j] += a[i][k] * b[k][j];

        printf("Case %d: %lld\n", t++, temp[2][0] % mod);
    }
    return 0;
}
