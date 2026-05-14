class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i];

            int new_max = max(val, val * max_so_far);
            new_max = max(new_max, val * min_so_far);

            int new_min = min(val, val * min_so_far);
            new_min = min(new_min, val * max_so_far);

            max_so_far = new_max;
            min_so_far = new_min;

            result = max(result, max_so_far);
        }

        return result;
    }
};