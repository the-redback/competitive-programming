class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        map<char, int> mp;

        mp['('] = 1;
        mp[')'] = -1;
        mp['{'] = 2;
        mp['}'] = -2;
        mp['['] = 3;
        mp[']'] = -3;

        for(char ch : s){
            if(mp[ch] > 0){
                st.push(ch);
            } else {
                if(st.empty() || mp[ch] + mp[st.top()] != 0)
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
