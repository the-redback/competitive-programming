#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        unordered_map<string, bool> w;

        for (auto s : words) w[s] = true;

        int ans = 0;
        for (auto s : words) {
            ans = max(ans, rec(w, dp, s));
        }
        return ans;
    }

    int rec(unordered_map<string, bool>& w, unordered_map<string, int>& dp, string curr) {
        if (dp[curr] > 0) return dp[curr];

        int len = 1;

        for (int i = 0; i < curr.size(); i++) {
            string newWord = curr.substr(0, i) + curr.substr(i + 1);
            if (w.find(newWord) != w.end()) {
                len = max(len, rec(w, dp, newWord) + 1);
            }
        }

        return dp[curr] = len;
    }
};