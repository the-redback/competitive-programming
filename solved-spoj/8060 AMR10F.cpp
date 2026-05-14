#include <bits/stdc++.h>
using namespace std;

main() {
    long long sum, n, m, k, i, j;
    int t, tc;
    cin >> tc;
    t = 1;
    while (tc--) {
        cin >> n >> m >> k;
        sum = m;
        for (i = 1; i < n; i++) {
            sum += m + (k * i);
        }
        cout << sum << endl;
    }
    return 0;
}
