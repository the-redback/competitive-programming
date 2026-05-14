#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        rec(digits, "", 0);
        return ans;
    }

private:
    map<int, string> mp;
    vector<string> ans;

    void rec(string& digits, string str, int pos) {
        if (pos == digits.size()) {
            ans.push_back(str);
            return;
        }
        string ss = mp[digits[pos] - '0'];
        for (auto s : ss) {
            rec(digits, str + s, pos + 1);
        }
        return;
    }
};