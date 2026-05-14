#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (!s.size() || !words.size()) return ans;

        int N = s.size();
        int k = words[0].size();
        int wordLength = words.size();

        unordered_map<string, int> mp;
        for (auto s : words) mp[s]++;

        for (int offset = 0; offset < k; offset++) {
            unordered_map<string, int> currCount;
            int start = offset;
            int count = 0;

            for (int end = offset; end + k <= N; end += k) {
                string curr = s.substr(end, k);

                if (mp.find(curr) != mp.end()) {
                    currCount[curr]++;
                    count++;

                    while (currCount[curr] > mp[curr]) {
                        string startWord = s.substr(start, k);
                        currCount[startWord]--;
                        count--;
                        start += k;
                    }

                    if (count == wordLength) ans.push_back(start);
                } else {
                    currCount.clear();
                    start = end + k;
                    count = 0;
                }
            }
        }

        return ans;
    }
};