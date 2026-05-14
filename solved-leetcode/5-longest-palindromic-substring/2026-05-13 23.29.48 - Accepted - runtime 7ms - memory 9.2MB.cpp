class Solution {
public:
    int expand(int i, int j, string& s) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--, j++;
        }
        return j - i - 1; // because s[i] != s[j] after while loop.
    }

    string longestPalindrome(string s) {
        int in = -1, result = 0;

        for (int i = 0; i < s.size(); i++) {
            int k = expand(i, i, s);
            k = max(k, expand(i, i + 1, s));

            if (k > result) {
                in = i - (k - 1) / 2;
                result = k;
            }
        }

        return s.substr(in, result);
    }
};