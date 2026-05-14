class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        map<char,int>mp;
        mp['(']=1;
        mp[')']=-1;
        mp['{']=2;
        mp['}']=-2;
        mp['[']=3;
        mp[']']=-3;

        for(int i=0;i<s.size();i++){
            if(mp[s[i]]<0)
            {
                if(st.empty()|| mp[st.top()]+mp[s[i]]!=0)
                    return false;
                st.pop();
            }
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};