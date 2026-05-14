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

#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define NN        1050

int parent[100010];
int tree[300010];

void makeTree(int node, int low, int high) {
    if (low == high) {
        tree[node] = parent[low];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (low + high) / 2;

    makeTree(left, low, mid);
    makeTree(right, mid + 1, high);
    tree[node] = min(tree[right], tree[left]);
    return;
}

int minValue(int node, int low, int high, int rlow, int rhigh) {
    if (low >= rlow && high <= rhigh) return tree[node];
    int left = node * 2;
    int right = left + 1;
    int mid = (low + high) / 2;

    if (rhigh <= mid)
        return minValue(left, low, mid, rlow, rhigh);
    else if (rlow > mid)
        return minValue(right, mid + 1, high, rlow, rhigh);
    else {
        left = minValue(left, low, mid, rlow, rhigh);
        right = minValue(right, mid + 1, high, rlow, rhigh);
        return min(left, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc, i, t;
    cin >> tc;
    for (t = 1; t <= tc; t++) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> parent[i];
        makeTree(1, 1, n);
        printf("Case %d:\n", t);
        while (q--) {
            int i, j;
            cin >> i >> j;
            int k = minValue(1, 1, n, i, j);
            printf("%d\n", k);
        }
    }
    return 0;
}
