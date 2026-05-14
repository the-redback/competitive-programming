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
                if(emails[i][j]=='@')
                {
                    str+=emails[i].substr(j,emails[i].size()-j);
                    break;
                }
                else if(plus ||emails[i][j]=='+')
                {
                    plus=true;
                }
                else if(emails[i][j]!='.')
                    str+=emails[i][j];
            }
            cout<<str<<"\n";
            if(mp.find(str)==mp.end())
            {
                mp[str]=true;
                cnt++;
            }
        }
        return cnt;
    }
};