#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[customSort(s)].push_back(s);
        }
        vector<vector<string>> result;
        for (auto m : mp) {
            result.push_back(m.second);
        }

        return result;
    }

    string customSort(string& s) {
        int a[27] = {0};

        for (auto ch : s) a[ch - 'a']++;

        string t = "";

        for (int i = 0; i < 26; i++) {
            t += string(a[i], i + 'a');
        }

        return t;
    }
};