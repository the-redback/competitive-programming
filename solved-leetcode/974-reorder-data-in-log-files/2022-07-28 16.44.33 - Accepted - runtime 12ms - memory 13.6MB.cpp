#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cctype>

using namespace std;

static bool comp(pair<string, string> a, pair<string, string> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits, ans;
        vector<pair<string, string> > letter;

        for (auto str : logs) {
            if (isalpha(str[str.size() - 1])) {
                int in = str.find(' ');
                string s1 = str.substr(0, in);
                string s2 = str.substr(in + 1);
                letter.push_back({s1, s2});
            } else
                digits.push_back(str);
        }

        sort(letter.begin(), letter.end(), comp);

        for (auto p : letter) {
            ans.push_back(p.first + " " + p.second);
        }
        for (auto str : digits) ans.push_back(str);

        return ans;
    }
};