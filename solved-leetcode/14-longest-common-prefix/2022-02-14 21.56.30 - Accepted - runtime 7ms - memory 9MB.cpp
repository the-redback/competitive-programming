class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        
        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(i>=strs[j].size() || ch !=strs[j][i])
                    return prefix;
            }
            prefix+=ch;
        }
        return prefix;
    }
};