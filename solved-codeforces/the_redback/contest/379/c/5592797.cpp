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
#define inf HUGE_VAL

vector<int> v;
int a[300030];

bool comp(int i, int j) { return a[i] < a[j]; }

int main() {
    // freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    int tc, t = 1;
    int i, j, k, n;
    while (~scanf("%d", &n)) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            v.push_back(i);
        }
        sort(v.begin(), v.end(), comp);
        int last = -inf;
        for (i = 0; i < n; i++) {
            k = v[i];
            if (last < a[k]) {
                last = a[k];
            } else {
                last++;
                a[k] = last;
            }
        }
        for (i = 0; i < n; i++) {
            if (i != 0) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
        v.clear();
    }
    return 0;
}
