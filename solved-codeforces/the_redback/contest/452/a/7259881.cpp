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

#define ll        long long
#define LL        __int64
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define NN        1050

char a[20][20] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char b[20];

int check(int i, int n) {
    int m = strlen(a[i]);
    if (m != n) return 0;
    int j;
    for (j = 0; j < n; j++)
        if (b[j] != '.' && a[i][j] != b[j]) return 0;
    return 1;
}

main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc;
    // cin>>tc;
    int i, j, k, l, m, n;
    while (cin >> n) {
        scanf("%s", &b);
        for (i = 0; i < 8; i++)
            if (check(i, n)) {
                puts(a[i]);
                break;
            }
    }
    return 0;
}
