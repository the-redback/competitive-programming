class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
        
        unordered_map<char,int>mp;

        for(auto ch: magazine)
            mp[ch]++;
        
        for(auto ch: ransomNote)
            mp[ch]--;

        for(auto m: mp){
            if(m.second < 0)
                return false;
        }

        return true;
    }
};