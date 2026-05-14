class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mp;
        for(int i=0; i<s.size(); i++)
            mp[s[i]] = i;
        
        vector<int>result;
        int last=-1;
        int mx = 0;
        
        for(int i=0; i<s.size(); i++){
            mx = max(mx, mp[s[i]]);
            if(mx == i){
                result.push_back(mx-last);
                last=mx;
            }
        }
        
        return result;
    }
};