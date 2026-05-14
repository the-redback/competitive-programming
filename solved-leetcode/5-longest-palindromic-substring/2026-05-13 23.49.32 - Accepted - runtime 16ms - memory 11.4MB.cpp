#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Transform S into s_prime.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    string preprocess(string& s) {
        int n = s.size();
        if (n == 0) return "^$";

        string s_prime = "^";
        for (auto ch : s) {
            s_prime += "#";
            s_prime += ch;
        }
        s_prime += "#$";
        return s_prime;
    }

    string longestPalindrome(string& s) {
        string s_prime = preprocess(s);

        int n = s_prime.size();
        vector<int> radius(n, 0);

        int center = 0;
        int right = 0;

        for (int i = 1; i < n - 1; i++) {
            int i_prime = center - (center - i);

            // Mirror if within range.
            if (right > i) {
                radius[i] = min(right - i, radius[i_prime]);
            }

            // Attempt to expand palindrome centered at i
            while (s_prime[i + radius[i] + 1] == s_prime[i - radius[i] - 1]) {
                radius[i]++;
            }

            // If the palindrome centered at i expands past right,
            // update center to i and right to new position.
            if (i + radius[i] > right) {
                center = i;
                right = i + radius[i];
            }
        }

        // Find the maximum element in s_prime
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (radius[i] > maxLen) {
                maxLen = radius[i];
                centerIndex = i;
            }
        }

        int actualIndex = (centerIndex - maxLen - 1) / 2;

        return s.substr(actualIndex, maxLen);
    }
};