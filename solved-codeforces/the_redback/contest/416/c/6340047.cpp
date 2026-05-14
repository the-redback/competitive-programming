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

#define ppb       pop_back
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       2000000000
#define eps       1e-9
#define NN        400010

struct D {
    int c, p, id;
    D(int C, int P, int I) { c = C, p = P, id = I; }
    D() {}
};
struct A {
    int j, t;
    A(int J, int T) { j = J, t = T; }
    A() {}
};
vector<D> v;
vector<A> ans;
A a[1010];

bool comp(D x, D y) {
    if (x.p == y.p) return x.c < y.c;
    return x.p > y.p;
}

bool cmp(A x, A y) { return x.j < y.j; }

int main() {
    ios_base::sync_with_stdio(false);
    int t, tc;
    // cin>>tc;
    int n, m, i, j, k, l;
    int r;
    int low, high;
    while (cin >> n) {
        v.clear();
        ans.clear();
        for (i = 1; i <= n; i++) {
            cin >> k >> l;
            v.pb(D(k, l, i));
        }
        cin >> m;
        int mx = 0;
        for (i = 0; i < m; i++) {
            cin >> r;
            a[i] = A(r, i + 1);
        }
        sort(all(v), comp);
        sort(a, a + m, cmp);
        int tbl = 0, sum = 0;
        for (i = 0; i < n; i++) {
            r = v[i].c;
            for (j = 0; j < m; j++) {
                if (a[j].j >= r) {
                    tbl++;
                    sum += v[i].p;
                    a[j].j = -1;
                    ans.pb(A(v[i].id, a[j].t));
                    break;
                }
            }
        }
        printf("%d %d\n", tbl, sum);
        for (i = 0; i < ans.size(); i++) {
            printf("%d %d\n", ans[i].j, ans[i].t);
        }
    }
    return 0;
}
