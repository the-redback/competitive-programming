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
#define inf       1000000000
#define NN        1000000

vector<int> v;

int main() {
    int i, j, k, l;
    int tc, t;
    int n, m, x, y;
    while (~scanf("%d:%d", &n, &m)) {
        scanf("%d:%d", &x, &y);
        int flag = 0;
        l = (m - y);
        if (l < 0) {
            flag = 1;
            l = 60 + l;
        }
        k = (n - x - flag);
        if (k < 0) k = 24 + k;
        printf("%02d:%02d\n", k, l);
    }
    return 0;
}
