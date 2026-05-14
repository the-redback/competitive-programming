class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        for (auto& ch : jewels) {
            mp[ch] = true;
        }

        int ans = 0;
        for (auto& ch : stones) {
            if (mp.find(ch) != mp.end()) ans++;
        }
        return ans;
    }

    unordered_map<char, bool> mp;
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
