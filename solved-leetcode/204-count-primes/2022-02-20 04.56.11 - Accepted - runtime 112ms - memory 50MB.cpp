#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int dp[5000001];
    void precalculate() {
        int n = 5000000;
        vector<int> p(n + 1);
        for (int i = 2; i * i < n; i++) {
            if (p[i] == 0) {
                for (int j = i * i; j < n; j += i) {
                    p[j] = 1;
                }
            }
        }

        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1];
            if (!p[i]) dp[i]++;
        }
    }

public:
    Solution() {
        static int x = 0;
        if (x == 0) {
            cout << "here!";
            precalculate();
            x++;
        }
    }
    int countPrimes(int n) {
        if (n != 0) return dp[n - 1];
        return 0;
    }
};