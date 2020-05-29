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

typedef long long ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define meminf(a) memset(a, 126, sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       10007
#define NN        30100

// cout << setfill('0') << setw(3) << a << endl;
// cout << fixed << setprecision(20) << a << endl;

/*
    f(n+1)= a1*f(n) + b1*f(n-1)+ c1*g(n-2)
    g(n+1)= a2*g(n) + b2*g(n-1)+ c2*f(n-2)


   |a1 b1 0  0  0  c1 |^k   |f(2)|   |f(k+2)|
   |1  0  0  0  0  0  |     |f(1)|   |f(k+1)|
   |0  1  0  0  0  0  |     |f(0)|   | f(k) |
   |0  0  c2 a2 b2 0  |  *  |g(2)| = |g(k+2)|
   |0  0  0  1  0  0  |     |g(1)|   |g(k+1)|
   |0  0  0  0  1  0  |     |g(0)|   | g(k) |
*/

ll M;
ll a1, b1, c1;
ll a2, b2, c2;

ll m[8][8];
ll g[4], f[4];

void mult(ll a[8][8], ll b[8][8]) {
    ll temp[8][8];
    int i, j, k;
    mem(temp, 0);
    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++)
            for (k = 0; k < 6; k++) temp[i][j] += a[i][k] * b[k][j];
    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++) a[i][j] = temp[i][j] % M;
    return;
}

void BigMat(ll a[8][8], int pos) {
    int i, j, k;
    if (pos == 1) return;
    if (pos % 2 == 1) {
        BigMat(a, pos - 1);
        mult(a, m);
    } else {
        BigMat(a, pos / 2);
        mult(a, a);
    }
    return;
}

void init(ll a[8][8]) {
    ll i, j, k;
    mem(a, 0);
    mem(m, 0);
    m[0][0] = a1, m[0][1] = b1, m[0][5] = c1;
    m[1][0] = 1, m[2][1] = 1;
    m[3][2] = c2, m[3][3] = a2, m[3][4] = b2;
    m[4][3] = 1, m[5][4] = 1;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++) a[i][j] = m[i][j];
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, tc;
    cin >> tc;
    ll i, j, k, l, n;

    ll r;
    while (tc--) {
        cin >> a1 >> b1 >> c1;
        cin >> a2 >> b2 >> c2;
        cin >> f[0] >> f[1] >> f[2];
        cin >> g[0] >> g[1] >> g[2];
        cin >> M;

        cin >> r;
        printf("Case %d:\n", t++);

        ll b[8][2], a[8][8], temp[8][2];
        b[0][0] = f[2], b[1][0] = f[1], b[2][0] = f[0], b[3][0] = g[2],
        b[4][0] = g[1], b[5][0] = g[0];

        while (r--) {
            cin >> n;
            if (n <= 2) {
                printf("%lld %lld\n", f[n] % M, g[n] % M);
                continue;
            }
            init(a);
            BigMat(a, n);
            mem(temp, 0);
            for (i = 0; i < 6; i++)
                for (j = 0; j < 1; j++)
                    for (k = 0; k < 6; k++) temp[i][j] += a[i][k] * b[k][j];

            printf("%lld %lld\n", temp[2][0] % M, temp[5][0] % M);
        }
    }
    return 0;
}
