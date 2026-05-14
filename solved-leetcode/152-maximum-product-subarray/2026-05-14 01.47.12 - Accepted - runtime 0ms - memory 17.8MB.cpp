#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            int temp_max_so_far = max_so_far;

            max_so_far = max(val, max(temp_max_so_far * val, min_so_far * val));
            min_so_far = min(val, min(temp_max_so_far * val, min_so_far * val));

            result = max(result, max_so_far);
        }
        return result;
    }
};