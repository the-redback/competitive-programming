class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        string ans;

        int inc = 2 * (numRows - 1);

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j += inc) {
                ans += s[j];

                if (i > 0 && i < numRows - 1 && j + (inc - 2 * i) < s.length()) ans += s[j + (inc - 2 * i)];
            }
        }

        return ans;
    }
};