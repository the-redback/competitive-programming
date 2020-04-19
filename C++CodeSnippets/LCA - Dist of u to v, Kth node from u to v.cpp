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
#define NN        10010

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

/*

DIST a b : ask for the distance between node a and node b
or
KTH a b k : ask for the k-th node on the path from node a to node b

*/

ll par[NN];      //Parent
ll level[NN];    //level in tree
bool color[NN];   //DFS color
ll dist[NN];     //distance from root
ll P[NN][20];    //Sparse table
vector<ll>g[NN]; //Gragh store
vector<ll>cost[NN];

//1 based index.

void dfs(ll u) {
    ll i, v;
    color[u] = 1;

    for (i = 0; i < g[u].size(); i++) {
        v = g[u][i];
        if (color[v] == 0) {
            par[v] = u;
            level[v] = level[u] + 1;
            dist[v] = dist[u] + cost[u][i];
            dfs(v);
        }
    }
    return;
}

ll lca_query(ll p, ll q) {
    if (level[p] < level[q])
        swap(p, q);
    ll i, j, k, log;
    log = 1;
    while (1) {
        ll next = log + 1;
        if (1 << next > level[p])
            break;
        log++;
    }
    for (i = log; i >= 0; i--)
        if (level[p] - (1 << i) >= level[q])
            p = P[p][i];
    if (p == q)
        return p;
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    return par[p];

}


void lca_init(ll n) {
    mem(color, 0);
    mem(P, -1);
    level[1] = 0;
    dist[1] = 0;
    dfs(1);

    ll i, j;

    for (i = 1; i <= n; i++)
        P[i][0] = par[i];

    for (j = 1; 1 << j <= n; j++)
        for (i = 1; i <= n; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];

    return;
}

ll DIST(ll p, ll q) {
    ll temp = dist[p] + dist[q];
    ll node = lca_query(p, q);
    temp -= 2 * dist[node];
    return temp;
}

ll KTH(ll p, ll q, ll k) {
    k--;
    int i, j;
    ll node = lca_query(p, q);

    ll temp = level[p] - level[node];

    if (temp >= k) {
        ll LVL = level[p] - k;
        for (j = 20; j >= 0; j--)
            if (level[p] - (1 << j) >= LVL)
                p = P[p][j];
        return p;
    }
    k -= temp;

    temp = level[q] - level[node];
    temp -= k;
    ll LVL = level[q] - temp;
    for (j = 15; j >= 0; j--)
        if (level[q] - (1 << j) >= LVL)
            q = P[q][j];
    return q;
}

char s[10];

main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc;
    scanf("%d", &tc);
    ll i, j, k, l, n;
    ll r;
    while (tc--) {
        scanf("%lld", &n);
        for (i = 0; i <= n; i++) {
            g[i].clear();
            cost[i].clear();
        }

        for (i = 0; i < n - 1; i++) {
            scanf("%lld %lld %lld", &k, &l, &r);
            g[k].pb(l);
            g[l].pb(k);
            cost[k].pb(r);
            cost[l].pb(r);
        }
        lca_init(n);

        while (1) {
            scanf("%s", s);
            if (strcmp(s, "DONE") == 0)
                break;
            if (strcmp(s, "DIST") == 0) {
                scanf("%lld %lld", &k, &l);
                ll ret = DIST(k, l);
                printf("%lld\n", ret);
            } else {
                scanf("%lld %lld %lld", &k, &l, &r);
                ll ret = KTH(k, l, r);
                printf("%lld\n", ret);
            }
        }
        //if(tc)
        puts("");

    }
    return 0;
}

/*

input:
1

6
1 2 1
2 4 1
2 5 2
1 3 1
3 6 2
DIST 4 6
KTH 4 6 4
DONE

Output:
5
3

*/
