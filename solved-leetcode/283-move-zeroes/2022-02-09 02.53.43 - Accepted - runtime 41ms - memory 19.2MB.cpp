#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        int count = 0;
        while (fast < nums.size() && slow < nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            } else
                count++;
            fast++;
        }
        while (count > 0) {
            nums[slow] = 0;
            slow++;
            count--;
        }
    }
};