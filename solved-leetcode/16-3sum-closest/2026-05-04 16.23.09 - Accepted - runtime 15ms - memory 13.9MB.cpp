#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 10000000;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                int tmp = twosum(nums, i, target);
                if (abs(target - tmp) < abs(target - ans)) ans = tmp;
            }
        }
        return ans;
    }

    int twosum(vector<int>& nums, int k, int target) {
        int tmp = 10000000;
        for (int i = k + 1, j = nums.size() - 1; i < j;) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                return target;
            }
            if (abs(target - sum) < abs(target - tmp)) tmp = sum;

            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return tmp;
    }
};