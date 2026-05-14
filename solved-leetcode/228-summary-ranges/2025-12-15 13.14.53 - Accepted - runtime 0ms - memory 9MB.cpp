class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        for (int i = 0; i < nums.size(); i++) {
            int startPos = i;

            while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) {
                i++;
            }

            if (startPos != i)
                ans.push_back(to_string(nums[startPos]) + "->" + to_string(nums[i]));
            else
                ans.push_back(to_string(nums[startPos]));
        }

        return ans;
    }
};