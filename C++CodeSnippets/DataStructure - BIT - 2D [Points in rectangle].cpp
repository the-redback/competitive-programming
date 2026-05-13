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
  1)=>  0 x y, meaning that you have got a new point whose co-ordinate is (x,
  y). But the restriction is that, if a point (x, y) is already listed, then
  this query has no effect.

  2)=>  1 x1 y1 x2 y2 meaning that you are given a rectangle whose lower left
  co-ordinate is (x1, y1) and upper-right corner is (x2, y2); your task is to
  find the number of points, given so far, that lie inside this rectangle. You
  can assume that (x1 < x2, y1 < y2).
*/

int tree[NN][NN];
bool flag[NN][NN];
int max_x, max_y;

void update(int idx, int idy, int val) {
    int y;
    while (idx <= max_x) {
        y = idy;
        while (y <= max_y) {
            tree[idx][y] += val;
            y += y & -y;
        }
        idx += idx & -idx;
    }
    return;
}

int query(int idx, int idy) {
    int sum = 0, y;
    while (idx > 0) {
        y = idy;
        while (y > 0) {
            sum += tree[idx][y];
            y -= y & -y;
        }
        idx -= idx & -idx;
    }
    return sum;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, tc;
    cin >> tc;
    int i, j, k, l, n;
    int x1, x2, y1, y2;
    int r;
    while (tc--) {
        printf("Case %d:\n", t++);
        cin >> n;
        memset(flag, 0, sizeof(flag));
        memset(tree, 0, sizeof(tree));
        max_x = max_y = 1001;
        while (n--) {
            cin >> j;
            if (j == 0) {
                cin >> x1 >> y1;
                x1++, y1++;
                if (flag[x1][y1] == 0) {
                    flag[x1][y1] = 1;
                    // max_x=max(max_x,x1);
                    // max_y=max(max_y,y1);
                    update(x1, y1, 1);
                }
            } else {
                cin >> x1 >> y1 >> x2 >> y2;
                x1++, y1++, x2++, y2++;
                int temp = query(x2, y2);
                temp -= query(x2, y1 - 1);
                temp -= query(x1 - 1, y2);
                temp += query(x1 - 1, y1 - 1);
                printf("%d\n", temp);
            }
        }
    }
    return 0;
}

/*
Sample Input
------------
1
6
0 1 1
0 2 3
0 4 5
1 1 1 4 5
0 1 1
1 2 2 4 5

Sample Output
-------------
Case 1:
3
2

Explanation
-----------
Inserted points:
(1,1), (2,3), (4,5)

Query 1:
Rectangle from (1,1) to (4,5)
Points inside = 3

Duplicate insertion:
(1,1) is ignored

Query 2:
Rectangle from (2,2) to (4,5)
Points inside = 2
*/
