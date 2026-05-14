class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};

        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else
                high = mid;
        }
        if (nums[low] != target) return {-1, -1};

        int l1 = low;
        high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (nums[mid] <= target) {
                low = mid;
            } else
                high = mid - 1;
        }
        return {l1, low};
    }
};