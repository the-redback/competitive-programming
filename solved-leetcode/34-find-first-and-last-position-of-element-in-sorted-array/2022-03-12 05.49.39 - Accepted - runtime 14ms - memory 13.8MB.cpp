#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};

        int low = findBound(nums, target, 0, true);
        if (low == -1) return {-1, -1};

        int high = findBound(nums, target, low, false);

        return {low, high};
    }

    int findBound(vector<int>& nums, int target, int low, bool isFirst) {
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else {
                if (isFirst) {
                    // lower bound
                    if (mid == low || nums[mid - 1] != target) {
                        return mid;
                    }
                    high = mid - 1;
                } else {
                    if (mid == high || nums[mid + 1] != target) {
                        return mid;
                    }
                    low = mid + 1;
                }
            }
        }

        return -1;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);