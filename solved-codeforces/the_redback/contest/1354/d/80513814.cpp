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

int tree[4000000];

void update(int node, int low, int high, int pos, int val) {
    if (low == pos && high == pos) {
        tree[node] += val;
        return;
    }
    int left  = node * 2;
    int right = left + 1;
    int mid   = (low + high) / 2;

    if (pos <= mid)
        update(left, low, mid, pos, val);
    else
        update(right, mid + 1, high, pos, val);
    tree[node] = tree[right] + tree[left];
    return;
}

int query(int node, int low, int high, int k) {
    if (low == high) {
        return low;
    }
    int mid   = (low + high) / 2;
    int left  = node * 2;
    int right = left + 1;
    if (k > tree[node]) {
        return 0;
    }
    if (k <= tree[left])
        return query(left, low, mid, k);
    else
        return query(right, mid + 1, high, k - tree[left]);

    return 0;
}

void solve(ll n, ll m) {
    ll i, j, k;
    // cin >> n >> m;
    mem(tree, 0);

    for (i = 0; i < n; i++) {
        cin >> k;
        update(1, 1, n, k, 1);
    }
    for (i = 0; i < m; i++) {
        cin >> k;
        if (k < 0) {
            k *= -1;
            ll q = query(1, 1, n, k);
            update(1, 1, n, q, -1);
        } else {
            update(1, 1, n, k, 1);
        }
    }

    cout << query(1, 1, n, 1) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
    return 0;
}
