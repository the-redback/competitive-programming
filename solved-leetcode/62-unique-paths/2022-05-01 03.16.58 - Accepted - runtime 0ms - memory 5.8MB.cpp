#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) { return nCr(m + n - 2, m - 1); }

    int nCr(int n, int r) {  //
        int k, l;
        k = max(r, n - r);
        l = min(r, n - r);
        long long sum = 1;
        int i;
        int j = 1;
        for (i = k + 1; i <= n; i++) {
            sum *= i;
            if (j <= l && sum % j == 0) {
                sum /= j;
                j++;
            }
        }
        return (int)sum;
    }
};
