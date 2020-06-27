/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>
using namespace std;

#define mp        make_pair
#define pb(x)     push_back(x)
#define pp(x)     pop_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define NN        1050

struct P {
    double x, y;
    P(double X, double Y) {
        x = X;
        y = Y;
    }
    P() {}
};

vector<P> v;

P MV(P a, P b) {
    return P(b.x - a.x, b.y - a.y);
}

double DP(P a, P b) {
    return a.x * b.x + a.y * b.y;
}

double CP(P a, P b) {
    return a.x * b.y - a.y * b.x;
}

double A(P a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

P ADD(P a, P b) {
    return P(a.x + b.x, a.y + b.y);
}

P LV(P a, double l) {
    return P(a.x * l / A(a), a.y * l / A(a));
}

P pvt;

bool comp(P a, P b) {   // False hoile sort korbe
    long long c = CP(MV(pvt, a), MV(pvt, b));
    if (c)
        return c > 0;
    return A(MV(pvt, a)) < A(MV(pvt, b));
}

void checkPvt(void) {
    pvt.x = inf;
    pvt.y = inf;
    for (int i = 0; i < v.size(); i++) {
        if (pvt.x > v[i].x)
            pvt = v[i];
        else if (pvt.x == v[i].x && pvt.y > v[i].y)
            pvt = v[i];
    }
}

vector<P> q;

void go(void) {
    q.clear();
    int n = v.size();
    q.pb(v[n - 1]);
    v.pp();
    for (int i = v.size() - 1; i >= 0; i--) {
        if (CP(MV(v[0], q[q.size() - 1]), MV(v[0], v[i])) == 0) {
            q.pb(v[i]);
            v.pp();
        } else
            break;
    }
    for (int i = 0; i < q.size(); i++) v.pb(q[i]);
}

main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    int i, j, k, l, m, n;
    double x, y, z, u, w, xx, yy, zz, d;
    double aa, bb, cc, dd;
    cin >> tc;
    while (tc--) {
        cin >> n;
        v.clear();
        for (i = 0; i < n; i++) {
            cin >> k >> l;
            v.pb(P(k, l));
        }
        checkPvt();
        sort(v.begin(), v.end(), comp);
        go();
        cout << (int)v.size() << "\n";
        for (i = 0; i < v.size(); i++) {
            cout << (int)v[i].x << " " << (int)v[i].y << "\n";
        }
    }
    return 0;
}
