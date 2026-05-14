class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        for (auto& str : strs) {
            mp[customSort(str)].push_back(str);
        }

        for (auto m : mp) {
            result.push_back(m.second);
        }
        return result;
    }

    string customSort(string s) {
        int a[26] = {0};

        for (auto ch : s) a[ch - 'a']++;

        string t = "";
        for (int i = 0; i < 26; i++) {
            t += i + 'a';
            t += to_string(a[i]);
        }
        return t;
    }
};