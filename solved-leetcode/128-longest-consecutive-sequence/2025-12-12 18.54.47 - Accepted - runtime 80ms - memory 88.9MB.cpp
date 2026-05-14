#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int long_streak = 0;
        for (auto num : s) {
            if (s.find(num - 1) != s.end()) {
                continue;
            }

            int curr_streak = 1;
            int cnum = num + 1;

            while (s.find(cnum) != s.end()) {
                curr_streak++;
                cnum++;
            }
            long_streak = max(long_streak, curr_streak);
        }

        return long_streak;
    }
};