#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) twoSum(nums, i, res);
        }
        return res;
    }

    void twoSum(vector<int>& nums, int k, vector<vector<int>>& res) {
        for (int i = k + 1, j = nums.size() - 1; i < j;) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                res.push_back({nums[i], nums[j], nums[k]});
                i++;
                j--;
                while (i < j && nums[i] == nums[i - 1]) i++;
            } else if (sum < 0)
                i++;
            else
                j--;
        }
    }
};