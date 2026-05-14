#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int in = -1, res = 0;
        for (int i = 0; i < s.size(); i++) {
            int k = findPal(s, i, i);
            if (i + 1 < s.size()) k = max(k, findPal(s, i, i + 1));

            if (res < k) {
                in = i - (k - 1) / 2;
                res = k;
            }
        }
        return s.substr(in, res);
    }

    int findPal(string& s, int i, int j) {
        if (s[i] != s[j]) return 0;
        int res = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - i - 1;
    }
};