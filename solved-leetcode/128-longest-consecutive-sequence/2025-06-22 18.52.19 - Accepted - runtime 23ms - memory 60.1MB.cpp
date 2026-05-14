class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.size()==0)
            return 0;

        int long_streak = 0;
        int cnum = nums[0];
        int curr_streak = 1;

        for(int i=1; i<nums.size(); i++){
            if(cnum + 1 > nums[i])
                continue;
            else if(cnum + 1 == nums[i]){
                cnum++;
                curr_streak++;
            } else {
                long_streak = max(long_streak, curr_streak);
                cnum = nums[i];
                curr_streak = 1;
            }
        }
        long_streak = max(long_streak, curr_streak);
        return long_streak;
    }
};