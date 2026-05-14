class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>ran,mag;

        for(auto ch: ransomNote)
            ran[ch]++;

        for(auto ch: magazine)
            mag[ch]++;
        
        for(auto m: ran){
            if(m.second > mag[m.first])
                return false;
        }

        return true;
    }
};