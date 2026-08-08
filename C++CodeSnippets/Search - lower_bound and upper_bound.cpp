int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n;  // Not n - 1
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n;  // Not n - 1
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (x > a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}
//==========================================

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lowerBound) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (high + low) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] == target) {
                ans = mid;
                if (lowerBound)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);

        if (first == -1)
            return {-1, -1};

        int last = binarySearch(nums, target, false);

        return {first, last};
    }
};