class Solution {
public:
    int uniqueLetterString(string s) {
        int left[26], mid[26];
        int ans=0;
        
        memset(left, -1, sizeof(left));
        memset(mid, -1, sizeof(mid));
        
        for(int i=0; i<s.size(); i++){
            int ch=s[i] - 'A';
            
            ans += (i - mid[ch]) * (mid[ch] - left[ch]);
            
            left[ch] = mid[ch];
            mid[ch] = i;
        }
        
        for(int ch=0; ch<26; ch++){
            ans += (s.size() - mid[ch]) * (mid[ch] - left[ch]);
        }
        
        return ans;
    }
};