#include <map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> mp;
        for (auto ch : chars) {
            mp[ch]++;
        }
        int ans = 0;
        for (auto word : words) {
            map<char, int> m;
            int fl = 0;
            for (auto ch : word) {
                m[ch]++;
                if (m[ch] > mp[ch]) {
                    fl = 1;
                    break;
                }
            }
            if (fl == 0) ans += word.size();
        }

        return ans;
    }
};