#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, result, i);
            }
        }
        return result;
    }

    void twoSum(vector<int>& nums, vector<vector<int>>& res, int k) {
        for (int i = k + 1, j = nums.size() - 1; i < j;) {
            int sum = nums[k] + nums[i] + nums[j];
            if (sum == 0) {
                res.push_back({nums[i], nums[j], nums[k]});
                i++;
                j--;
                while (nums[i] == nums[i - 1] && i < j) i++;
            } else if (sum < 0) {
                i++;
            } else {
                j--;
            }
        }
    }
};