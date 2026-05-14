class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string,bool>mp;
        int cnt=0;
        for(auto &email: emails){
            string str="";
            bool plus=false;
            for(int i=0;i<email.size();i++){
                if(email[i]=='@')
                {
                    str+=email.substr(i,email.size()-i);
                    break;
                }
                else if(plus ||email[i]=='+')
                {
                    plus=true;
                }
                else if(email[i]!='.')
                    str+=email[i];
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