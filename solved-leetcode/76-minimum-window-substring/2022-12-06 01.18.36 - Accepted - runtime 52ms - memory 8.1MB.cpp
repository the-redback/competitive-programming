#include <string>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mapt, maps;
        for (auto ch : t) {
            mapt[ch]++;
        }

        int ans = INT_MAX;
        int in = -1;
        int cnt = 0;
        int n = s.size();

        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            if (mapt.find(s[right]) == mapt.end()) {
                continue;
            }

            maps[s[right]]++;
            if (maps[s[right]] == mapt[s[right]]) cnt++;

            while (cnt == mapt.size() && left <= right) {
                if (ans > right - left + 1) {
                    ans = right - left + 1;
                    in = left;
                }
                if (maps.find(s[left]) == maps.end()) {
                    left++;
                    continue;
                }
                maps[s[left]]--;
                if (maps[s[left]] < mapt[s[left]]) {
                    cnt--;
                }
                left++;
            }
        }
        if (in == -1) return "";
        return s.substr(in, ans);
    }
};