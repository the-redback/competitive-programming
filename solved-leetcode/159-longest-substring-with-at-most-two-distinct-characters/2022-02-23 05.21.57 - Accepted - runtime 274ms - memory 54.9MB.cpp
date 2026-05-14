class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        int i = 0;
        map<char, int> mp;
        for (int j = 0; j < s.size(); j++) {
            mp[s[j]]++;
            while (mp.size() > 2) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};