#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> p(n + 1);
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (p[i] == 0) {
                cnt++;
                for (long long j = 1ll * i * i; j < n; j += i) {
                    p[j] = 1;
                }
            }
        }
        return cnt;
    }
};