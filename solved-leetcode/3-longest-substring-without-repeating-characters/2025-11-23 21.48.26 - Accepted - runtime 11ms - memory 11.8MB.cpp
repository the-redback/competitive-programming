class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp;

        int result = 0;
        int left = 0, right = 0;

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            while (mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
