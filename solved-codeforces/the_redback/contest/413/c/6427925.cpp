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
#define inf       1000000000
#define eps       1e-9
#define NN        200010

vector<int> v;
vector<long long> a;

long long rec(long long sum) {
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < a.size(); i++) {
        sum += max(a[i], sum);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, tc;
    // cin>>tc;
    int n, m, q, r, i, j, k, l;
    while (cin >> n >> m) {
        v.clear();
        a.clear();
        long long sum = 0;
        for (i = 0; i < n; i++) {
            cin >> k;
            v.pb(k);
            sum += k;
        }
        for (i = 0; i < m; i++) {
            cin >> k;
            a.pb(v[k - 1]);
            sum -= v[k - 1];
            v[k - 1] = -1;
        }
        sum = rec(sum);
        cout << sum << "\n";
    }
    return 0;
}
