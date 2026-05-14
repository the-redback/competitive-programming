class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += twosum(nums, i, target);
        }
        return sum;
    }

    int twosum(vector<int>& nums, int k, int target) {
        int ret = 0;
        for (int i = k + 1, j = nums.size() - 1; i < j;) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum >= target)
                j--;
            else {
                ret += j - i;
                i++;
            }
        }
        return ret;
    }
};