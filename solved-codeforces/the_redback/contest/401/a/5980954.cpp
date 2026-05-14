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

#define mem(a, b) memset(a, b, sizeof(a))
#define pb        push_back
#define pp        pop_back
#define inf       10000000
#define NN        2000100

using namespace std;

int main() {
    int r, z, q, result;

    while (cin >> r >> z) {
        result = 0;
        for (int i = 0; i < r; i++) {
            cin >> q;
            result += q;
        }
        if (result == 0)
            cout << 0 << endl;
        else if (abs(result) <= z)
            cout << 1 << endl;
        else {
            q = abs(result);
            int countt = q / z;
            if (q % z) countt++;
            cout << countt << endl;
        }
    }
    return 0;
}
