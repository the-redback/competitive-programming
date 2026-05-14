class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>ban(banned.begin(), banned.end());
        unordered_map<string, int>mp;
        int cnt=0;
        string ans="";
        
        for(int i=0; i<paragraph.size(); i++){
            string str="";
            while(i< paragraph.size() && isalpha(paragraph[i])){
                str += tolower(paragraph[i]);
                i++;
            }
            
            if(str.size() >0 && ban.find(str) == ban.end()){
                mp[str]++;
                if(mp[str] > cnt)
                    ans=str, cnt=mp[str];
            }
        }
        
        return ans;
    }
};