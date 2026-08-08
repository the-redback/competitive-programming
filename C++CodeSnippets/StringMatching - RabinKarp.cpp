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
#include <string>
#include <vector>
using namespace std;

int RabinKarp(string& str, string& pattern) {
    int n = str.size();
    int m = pattern.size();

    if (m > n) {
        return -1;
    }

    const long long base = 257;
    const long long mod = (1e9 + 7);

    long long pHash = 0;
    long long sHash = 0;
    long long power = 1;

    for (int i = 0; i < m - 1; i++) {
        power = (power * base) % mod;
    }

    for (int i = 0; i < m; i++) {
        pHash = (pHash * base + pattern[i]) % mod;
        sHash = (sHash * base + str[i]) % mod;
    }

    if (pHash == sHash && str.substr(0, m) == pattern) {
        return 0;
    }

    for (int i = m; i < n; i++) {
        sHash = ((sHash - str[i - m] * power % mod) + mod) % mod;
        sHash = (sHash * base + str[i]) % mod;

        if (pHash == sHash && str.substr(i - m + 1, m) == pattern) {
            return i - m + 1;
        }
    }

    return -1;
}

int main() {
    string s = "ababababababbababababbababababba";
    string p = "ababababba";

    cout << RabinKarp(s, p) << '\n';

    return 0;
}
