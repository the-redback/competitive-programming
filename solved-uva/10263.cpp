/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, b, sizeof(a))
#define pb        push_back
#define pp        pop_back
#define inf       10e9  // 10^9
#define meminf    100
#define eps       10e-9
#define NN        1000000
struct P {
    double x, y;
    P(double X, double Y) {
        x = X;
        y = Y;
    }
};

vector<P> v;

P MV(P a, P b) { return P(b.x - a.x, b.y - a.y); }

double DP(P a, P b) { return a.x * b.x + a.y * b.y; }

double A(P a) { return sqrt(a.x * a.x + a.y * a.y); }

P ADD(P a, P b) { return P(a.x + b.x, a.y + b.y); }

P CV(P a, P b, double l) {
    b = MV(a, b);
    return ADD(a, P(b.x * l / A(b), b.y * l / A(b)));
}

double MAX = inf;
P ans(0, 0);

P go(P a, P b, P c) {
    if (DP(MV(a, b), MV(a, c)) <= 0) {
        if (A(MV(a, c)) < MAX) {
            MAX = A(MV(a, c));
            return a;
        }
        return ans;
    }
    if (DP(MV(b, a), MV(b, c)) <= 0) {
        if (A(MV(b, a)) < MAX) {
            MAX = A(MV(b, a));
            return b;
        }
        return ans;
    }

    double l;
    l = DP(MV(a, b), MV(a, c)) / A(MV(a, b));
    double ac = A(MV(a, c));
    double res = sqrt((ac * ac) - (l * l));
    if (res < MAX) {
        MAX = res;
        return CV(a, b, l);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    int i, j, k, l, m, n;
    double x, y, z, u, w, xx, yy, zz, d;
    double aa, bb, cc, dd;
    // cin>>tc;
    while (cin >> xx >> yy >> n) {
        P p(0, 0);
        for (i = 0; i <= n; i++) {
            cin >> p.x >> p.y;
            v.pb(p);
        }
        MAX = inf;
        for (i = 1; i < v.size(); i++) {
            ans = go(v[i - 1], v[i], P(xx, yy));
        }
        v.clear();
        printf("%.4lf\n%.4lf\n", ans.x, ans.y);
    }
    return 0;
}
