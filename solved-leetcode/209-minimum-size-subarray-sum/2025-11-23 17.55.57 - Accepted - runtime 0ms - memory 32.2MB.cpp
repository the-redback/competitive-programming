#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currentSum = 0;
        int left = 0, right = 0;
        int count = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];

            while (currentSum >= target) {
                count = min(count, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        return count == INT_MAX ? 0 : count;
    }
};