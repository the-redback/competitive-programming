class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] <= nums[n - 1]) return nums[0];

        int low = 0, high = n - 1;
        while (low < high) {
            if (nums[low] <= nums[high]) return nums[low];

            int mid = (high + low) / 2.0;
            if (mid != 0 && nums[mid] < nums[mid - 1]) return nums[mid];

            if (nums[mid] >= nums[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[low];
    }
};