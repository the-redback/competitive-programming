/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    int k, l, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        int res = 0, cnt = 0, i;
        for (i = 0; i < n; i++) {
            cin >> k;
            res ^= k;
            if (k == 1) cnt++;
        }
        if (cnt == n) {
            if (!res)
                printf("Case %d: Alice\n", t++);
            else
                printf("Case %d: Bob\n", t++);
        } else {
            if (res)
                printf("Case %d: Alice\n", t++);
            else
                printf("Case %d: Bob\n", t++);
        }
    }
    return 0;
}
