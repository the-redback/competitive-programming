#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, result);
            }
        }

        return result;
    }

    void twoSum(vector<int>& nums, int i, vector<vector<int>>& result) {
        unordered_set<int> visited;

        for (int j = i + 1; j < nums.size(); j++) {
            int need = -nums[i] - nums[j];

            if (visited.find(need) != visited.end()) {
                result.push_back({nums[i], nums[j], need});

                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
            }

            visited.insert(nums[j]);
        }
        return;
    }
};