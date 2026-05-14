#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp;

        int left = 0, right = 0;
        int result = 0;

        for (right = 0; right < s.size(); right++) {
            if (mp.find(s[right]) != mp.end()) left = max(left, mp[s[right]] + 1);

            result = max(result, right - left + 1);
            mp[s[right]] = right;
        }

        return result;
    }
};