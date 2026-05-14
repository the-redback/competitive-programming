#include <string>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mapt;
        map<char, int> maps;

        for (auto ch : t) {
            mapt[ch]++;
        }

        int ans = INT_MAX;
        int in = -1;
        int cnt = 0;
        int n = t.size();
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (mapt.find(s[j]) == mapt.end()) {
                continue;
            }
            maps[s[j]]++;
            if (maps[s[j]] <= mapt[s[j]]) cnt++;
            // if(cnt==n){
            //     ans=min(ans,j-i+1);
            // }
            while (cnt == t.size() && i <= j) {
                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    in = i;
                }
                ans = min(ans, j - i + 1);
                if (maps.find(s[i]) == maps.end()) {
                    i++;
                    continue;
                }
                // increase i
                maps[s[i]]--;
                if (maps[s[i]] < mapt[s[i]]) cnt--;
                i++;
            }
        }
        if (in == -1) return "";
        return s.substr(in, ans);
    }
};