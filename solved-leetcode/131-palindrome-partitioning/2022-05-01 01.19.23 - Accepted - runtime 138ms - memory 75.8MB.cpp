#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }

    vector<vector<string>> result;
    vector<string> comb;

    void backtrack(string& s, int start) {
        if (start >= s.size()) {
            result.push_back(comb);
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                comb.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1);
                comb.pop_back();
            }
        }
        return;
    }

    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
};