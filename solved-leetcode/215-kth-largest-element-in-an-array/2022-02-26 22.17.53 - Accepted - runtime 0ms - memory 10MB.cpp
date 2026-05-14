#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int k_small = nums.size() - k;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int in = partition(nums, left, right);

            if (in == k_small) return nums[in];
            if (in < k_small) {
                left = in + 1;
            } else {
                right = in - 1;
            }
        }
        return nums[right];
    }

    int partition(vector<int>& nums, int left, int right) {
        if (left == right) return left;
        int pvt = left + rand() % (right - left + 1);
        swap(nums[pvt], nums[right]);
        int l = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < nums[right]) {
                swap(nums[l], nums[i]);
                l++;
            }
        }

        swap(nums[l], nums[right]);
        return l;
    }
};