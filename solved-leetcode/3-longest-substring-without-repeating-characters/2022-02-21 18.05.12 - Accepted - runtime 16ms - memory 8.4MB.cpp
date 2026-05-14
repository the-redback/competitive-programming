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
            if (mp.find(s[right]) != mp.end() && left <= mp[s[right]]) {
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right;
            res = max(res, right - left + 1);
        }
        return res;
    }
};