#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxSub = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            maxSub = max(maxSub, curr);
            if (curr < 0) curr = 0;
        }
        return maxSub;
    }
};