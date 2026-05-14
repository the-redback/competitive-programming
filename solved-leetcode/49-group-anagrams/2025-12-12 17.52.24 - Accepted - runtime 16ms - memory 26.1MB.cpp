class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(string &str: strs){
            string k=str;
            sort(k.begin(), k.end());
            mp[k].push_back(str);
        }

        vector<vector<string>>result;
        
        for(auto m: mp){
            result.push_back(m.second);
        }
        return result;
    }
};