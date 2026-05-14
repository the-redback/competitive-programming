class Solution{
    public:

    int lengthOfLongestSubstring(string s){
        unordered_map<int, int>mp;

        int result = 0;
        int left = 0, right = 0;

        for(int right=0; right<s.size(); right++){
            left = max(left, mp[s[right]]);
            result = max(result, right - left + 1);
            mp[s[right]] = right+1;
        }
        return result;
    }
};
