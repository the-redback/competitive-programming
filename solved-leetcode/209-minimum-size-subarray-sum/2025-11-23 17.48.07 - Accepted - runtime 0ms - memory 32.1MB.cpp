#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = nums[0];
        int left = 0;
        int right = 0;
        int count = nums.size() + 1;
        if (sum >= target) return 1;

        for (int i = 1; i < nums.size(); i++) {
            right = i;
            sum += nums[i];

            if (sum >= target) {
                count = min(count, right - left + 1);
            }

            while (sum - nums[left] >= target && left < right) {
                sum -= nums[left];
                left++;
                count = min(count, right - left + 1);
            }
        }

        if (count == nums.size() + 1) return 0;
        return count;
    }
};