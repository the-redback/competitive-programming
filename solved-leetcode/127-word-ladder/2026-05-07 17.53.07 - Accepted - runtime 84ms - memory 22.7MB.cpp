#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        int n = wordList.size();

        for (int i = 0; i < n; i++) {
            mp[wordList[i]] = i;
        }

        if (beginWord == endWord) return 0;

        vector<int> visited(n);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (int i = 0; i < u.first.size(); i++) {
                string str = u.first;
                for (int ch = 'a'; ch <= 'z'; ch++) {
                    str[i] = ch;

                    if (mp.find(str) == mp.end() || visited[mp[str]]) continue;

                    if (str == endWord) {
                        return u.second + 1;
                    }
                    visited[mp[str]] = 1;
                    q.push({str, u.second + 1});
                }
            }
        }

        return 0;
    }
};