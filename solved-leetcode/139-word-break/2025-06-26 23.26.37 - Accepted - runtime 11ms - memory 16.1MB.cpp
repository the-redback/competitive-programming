#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> visited(s.length(), false);
        q.push(0);

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            for (int i = start + 1; i <= s.size(); i++) {
                string str = s.substr(start, i - start);  // doesn't include i in the substring
                if (words.find(str) != words.end()) {
                    if (i == s.size()) return true;
                    if (!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
        return false;
    }
};