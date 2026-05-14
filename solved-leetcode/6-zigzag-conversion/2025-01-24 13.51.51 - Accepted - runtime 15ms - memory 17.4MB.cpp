class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        int row = 0, d = 1;

        vector<vector<char>> v(numRows);

        for (auto ch : s) {
            v[row].push_back(ch);

            if (row == 0) {
                d = 1;
            } else if (row == numRows - 1) {
                d = -1;
            }

            row += d;
        }

        string ans;
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v[i].size(); j++) ans += v[i][j];

        return ans;
    }
};