class Solution {
public:
    int expand(int i, int j, string& s) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--, j++;
        }

        // because s[i] != s[j] after while loop.
        return j - i - 1;
    }

    string longestPalindrome(string s) {
        int in = -1, result = 0;

        for (int i = 0; i < s.size(); i++) {
            int len = expand(i, i, s);           // Odd length palindrome
            len = max(len, expand(i, i + 1, s)); // Even length palindrome

            if (len > result) {
                in = i - (len - 1) / 2;
                result = len;
            }
        }

        return s.substr(in, result);
    }
};
