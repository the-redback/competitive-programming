#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
                count = 1;
            } else if (count < 2) {
                count++;
                nums[k] = nums[i];
                k++;
                count++;
            }
        }

        return k;
    }
};