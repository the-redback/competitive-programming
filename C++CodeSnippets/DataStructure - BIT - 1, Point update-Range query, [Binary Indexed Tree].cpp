/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <cstring>
#include <iostream>
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

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc;
    cin >> tc;

    ll i, j, k, l, m, n;
    while (tc--) {
        cin >> n >> m;
        memset(tree, 0, sizeof(tree));
        MaxVal = n;
        for (i = 1; i <= n; i++) {
            cin >> arr[i];
            update(i, arr[i]);
        }
        cout << "Case " << t++ << ":" << "\n";
        while (m--) {
            cin >> j;
            if (j == 1) {
                cin >> k;
                k++;
                update(k, -arr[k]);
                cout << arr[k] << "\n";
                arr[k] = 0;
            } else if (j == 2) {
                cin >> k >> l;
                k++;
                update(k, l);
                arr[k] += l;
            } else {
                cin >> k >> l;
                k++, l++;
                ll temp = query(l);
                temp -= query(k - 1);
                cout << temp << "\n";
            }
        }
    }
    return 0;
}

/*
Sample Input
------------
1
5 5
1 2 3 4 5
3 0 4
2 2 10
3 1 3
1 2
3 0 4

Sample Output
-------------
Case 1:
15
19
13
12

Explanation
-----------
Initial array:
[1, 2, 3, 4, 5]

Query 1:
3 0 4
Sum from index 0 to 4 = 15

Query 2:
2 2 10
Add 10 to index 2

Updated array:
[1, 2, 13, 4, 5]

Query 3:
3 1 3
Sum from index 1 to 3 = 19

Query 4:
1 2
Remove and print value at index 2
Printed value = 13

Updated array:
[1, 2, 0, 4, 5]

Query 5:
3 0 4
Sum from index 0 to 4 = 12
*/
