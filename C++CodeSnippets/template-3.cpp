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
#include <tuple>

using namespace std;

typedef long long ll;

#ifdef redback
struct debugger {
    template <typename T>
    debugger& operator,(const T& v) {
        cout << v << " ";
        return *this;
    }
} dbg;
#else
#endif  // debugging macros

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef redback
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif

    ll t = 1, tc;
    // cin >> tc ;
    ll n, m;
    while (cin >> n) {
        ll i, j, k;

        cout << n << "\n";
    }
    return 0;
}
