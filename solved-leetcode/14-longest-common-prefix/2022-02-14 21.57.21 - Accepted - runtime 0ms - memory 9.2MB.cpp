#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0].at(i);
            for (int j = 0; j < strs.size(); j++) {
                if (i >= strs[j].size() || ch != strs[j].at(i)) return prefix;
            }
            prefix += ch;
        }
        return prefix;
    }
};