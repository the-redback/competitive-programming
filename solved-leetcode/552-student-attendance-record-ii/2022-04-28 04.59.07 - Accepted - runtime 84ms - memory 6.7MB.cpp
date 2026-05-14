class Solution {
    long long mod = 1000000007;
    long f[100010];

public:
    Solution() {
        f[0] = 1;
        f[1] = 2;
        f[2] = 4;
        f[3] = 7;

        for (int i = 4; i <= 100000; i++) {
            f[i] = ((2 * f[i - 1]) % mod + (mod - f[i - 4]) % mod) % mod;
        }
    }

    int checkRecord(int n) {
        long sum = f[n];
        for (int i = 1; i <= n; i++) {
            sum += (f[i - 1] * f[n - i]) % mod;
        }

        return sum % mod;
    }
};