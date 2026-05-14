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

#define ppb       pop_back
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       2000000000
#define eps       1e-9
#define NN        400010

int main() {
    // ios_base::sync_with_stdio(false);
    int t, tc;
    // cin>>tc;
    int n, m, i, j, k, l;
    string s, SS;
    int low, high;
    while (cin >> n) {
        low = -inf;
        high = inf;
        while (n--) {
            cin >> s >> m >> SS;
            if (s == ">") {
                if (SS == "Y") {
                    low = max(low, m + 1);
                } else
                    high = min(high, m);
            }
            if (s == ">=") {
                if (SS == "Y") {
                    low = max(low, m);
                } else
                    high = min(high, m - 1);
            }
            if (s == "<") {
                if (SS == "Y") {
                    high = min(high, m - 1);
                } else
                    low = max(low, m);
            }
            if (s == "<=") {
                if (SS == "Y") {
                    high = min(high, m);
                } else
                    low = max(low, m + 1);
            }
        }
        if (low <= high) {
            cout << low << "\n";
        } else
            cout << "Impossible\n";
    }
    return 0;
}
