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

main() {
    // ios_base::sync_with_stdio(false);
    map<string, int> mp;
    string s;
    string ss;
    int ret = 0;
    int n, k, l, r, i;
    int tc, t = 1;
    scanf("%d", &n);
    scanf("%d", &tc);
    while (n--) {
        cin >> s >> k;
        mp[s] = k;
    }
    while (tc--) {
        l = 0;
        while (cin >> s) {
            if (s[0] == '.') break;
            if (mp.find(s) != mp.end()) {
                l += mp[s];
            }
        }
        cout << l << "\n";
    }
    return 0;
}
