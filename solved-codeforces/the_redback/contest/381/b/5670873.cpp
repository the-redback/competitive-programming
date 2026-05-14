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
#define inf       HUGE_VAL
#define mem(a, b) memset(a, b, sizeof(a))
#define mod       1000000007
int a[5050];

int main() {
    vector<int> v;

    int n, k, l, r, i;
    int tc, t = 1;
    while (~scanf("%d", &n)) {
        l = -inf;
        while (n--) {
            scanf("%d", &k);
            a[k]++;
            l = max(l, k);
        }
        for (i = 1; i <= l; i++) {
            if (a[i] > 0) {
                v.push_back(i);
                a[i]--;
            }
        }
        for (i = l - 1; i >= 1; i--) {
            if (a[i] > 0) {
                v.push_back(i);
                a[i]--;
            }
        }
        printf("%d\n", v.size());
        for (i = 0; i < v.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", v[i]);
        }
        puts("");
        v.clear();
    }
    return 0;
}
