#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int in = -1, result = 0;
        for (int i = 0; i < s.size(); i++) {
            int k = expand(s, i, i);
            k = max(k, expand(s, i, i + 1));

            if (result < k) {
                in = i - (k - 1) / 2;
                result = k;
            }
        }
        return s.substr(in, result);
    }

private:
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--, right++;
        }
        return right - left - 1;
    }
};