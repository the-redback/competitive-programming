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
#define NN        100050

int a[NN];
int arr[NN];
int flag[NN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc;
    // cin>>tc;
    int i, j, k, l, m, n;
    while (cin >> n) {
        for (i = 0; i < n; i++) cin >> a[i], arr[i] = a[i];
        int r = 1;
        mem(flag, -1);
        sort(arr, arr + n);

        int fl = -1, low, high;

        for (i = 0; i < n; i++) {
            if (arr[i] == a[i])
                flag[i] = 1;
            else if (fl == -1)
                low = i, fl = 1;
            else
                high = i;
        }
        int rlow, rhigh;
        rlow = low, rhigh = high;
        if (fl == -1) {
            puts("yes");
            printf("%d %d\n", 1, 1);
            continue;
        }

        while (rlow < rhigh) {
            swap(a[rlow], a[rhigh]);
            rlow++;
            rhigh--;
        }
        for (i = low; i <= high; i++)
            if (a[i] != arr[i]) break;
        if (i != high + 1)
            puts("no");
        else {
            puts("yes");
            printf("%d %d\n", low + 1, high + 1);
        }
    }
    return 0;
}
