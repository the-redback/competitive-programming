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

typedef long long ll;
typedef unsigned long long llu;

#define NN 10010

// cout << setfill('0') << setw(3) << a << endl;
// cout << fixed << setprecision(20) << a << endl;

/*
========================[ Theme ]===========================

   j=1 => input k          => a[k]=0;
   j=2 => input k,value    => a[k]+=value
   j=3 => input k,l        => output=a[k]+a[k+1]+....+a[l]

========================[ END ]=============================
*/

ll MaxVal;

ll tree[NN];
ll arr[NN];

ll update(ll idx, ll val) {
    while (idx <= MaxVal) {
        tree[idx] += val;
        idx += idx & (-idx);
    }
    return 0;
}

ll query(ll idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc;
    scanf("%d", &tc);

    ll i, j, k, l, m, n;
    while (tc--) {
        scanf("%lld %lld", &n, &m);
        memset(tree, 0, sizeof(tree));
        MaxVal = n;
        for (i = 1; i <= n; i++) {
            scanf("%lld", &arr[i]);
            update(i, arr[i]);
        }
        printf("Case %d:\n", t++);
        while (m--) {
            scanf("%lld", &j);
            if (j == 1) {
                scanf("%lld", &k);
                k++;
                update(k, -arr[k]);
                printf("%lld\n", arr[k]);
                arr[k] = 0;
            } else if (j == 2) {
                scanf("%lld %lld", &k, &l);
                k++;
                update(k, l);
                arr[k] += l;
            } else {
                scanf("%lld %lld", &k, &l);
                k++, l++;
                ll temp = query(l);
                temp -= query(k - 1);
                printf("%lld\n", temp);
            }
        }
    }
    return 0;
}
