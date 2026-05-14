class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int long_streak = 0;

        for (auto num : s) {
            if (s.find(num - 1) == s.end()) {
                int curr = 1;

                while (s.find(num + curr) != s.end()) {
                    curr++;
                }
                long_streak = max(long_streak, curr);
            }
        }

        return long_streak;
    }
};
