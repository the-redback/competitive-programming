#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int result = 0;
        int left = 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            while (mp.size() > 2) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};