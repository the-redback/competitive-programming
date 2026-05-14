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
int a[2000001];
int main() {
    ios_base::sync_with_stdio(false);
    int i, j, n, size;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        j = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            if (j != 0) {
                cout << " ";
            }
            cout << a[i];
            j = 1;
        }
        cout << "\n";
    }
    return 0;
}
