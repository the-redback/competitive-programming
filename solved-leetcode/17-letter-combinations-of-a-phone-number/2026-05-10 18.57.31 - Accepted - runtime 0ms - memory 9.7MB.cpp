#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> ans;
    unordered_map<int, string> keys = {{2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
                                       {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

    void rec(string& digits, string s, int pos) {
        if (pos == digits.size()) {
            ans.push_back(s);
            return;
        }

        string str_keys = keys[digits[pos] - '0'];
        for (auto ch : str_keys) {
            rec(digits, s + ch, pos + 1);
        }

        return;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};

        rec(digits, "", 0);
        return ans;
    }
};