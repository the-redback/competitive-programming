/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    int k, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        int res = 0;
        while (n--) {
            cin >> k;
            res ^= k;
        }
        if (res)
            cout << "Case " << t++ << ": Alice" << "\n";  // First move
        else
            cout << "Case " << t++ << ": Bob" << "\n";
    }
    return 0;
}
