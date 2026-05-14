#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int res = 0;
        int cur = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            left = max(left, mp[s[right]]);
            mp[s[right]] = right + 1;
            res = max(res, right - left + 1);
        }
        return res;
    }
};