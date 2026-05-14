#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int a[26] = {0};

        for (string& str : strs) {
            memset(a, 0, sizeof(a));
            for (char ch : str) a[ch - 'a']++;

            string t = "";
            for (int i = 0; i < 26; i++) {
                t += i + 'a';
                t += to_string(a[i]);
            }
            mp[t].push_back(str);
        }

        vector<vector<string>> result;

        for (auto m : mp) {
            result.push_back(m.second);
        }
        return result;
    }
};