class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string,bool>mp;
        int cnt=0;
        for(int i=0;i<emails.size();i++){
            string str="";
            bool at=false;
            bool plus=false;
            for(int j=0;j<emails[i].size();j++){
                if(at)
                    str+=emails[i][j];
                else if(emails[i][j]=='@')
                {
                    at=true;
                    str+=emails[i][j];
                }
                else if(plus)
                    continue;
                else if(emails[i][j]=='+')
                {
                    plus=true;
                }
                else if(emails[i][j]=='.')
                    continue;
                else
                    str+=emails[i][j];
            }
            if(mp.find(str)==mp.end())
            {
                mp[str]=true;
                cnt++;
            }
        }
        return cnt;
    }
};