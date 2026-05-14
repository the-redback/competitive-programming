class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            mp[customSort(s)].push_back(s);
        }
        vector<vector<string>> result;
        for(auto m: mp){
            result.push_back(m.second);
        }
        
        return result;
    }
    
    string customSort(string &s){
        string t=s;
        sort(t.begin(), t.end());
        return t;
    }
};