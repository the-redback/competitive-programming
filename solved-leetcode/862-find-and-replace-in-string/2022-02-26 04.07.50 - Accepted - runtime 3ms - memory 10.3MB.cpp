class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,int>>v;
        for(int i=0;i<indices.size();i++){
            v.push_back({indices[i],i});
        }
        sort(v.begin(),v.end());
        string ans="";
        
        int i=0; 
        for(int j=0;j<v.size() && i<s.size();){
            int k=v[j].second;
            if(v[j].first == i && i+sources[k].size()<=s.size() && 
               sources[k]==s.substr(i,sources[k].size())){
                ans+=targets[k];
                i+=sources[k].size();
                j++;
            } else {
                if(v[j].first == i)
                    j++;
                
                ans+=s[i];
                i++;
            }
            
        }
        while(i<s.size()){
            ans+=s[i];
            i++;
        }
        return ans;
    }
};