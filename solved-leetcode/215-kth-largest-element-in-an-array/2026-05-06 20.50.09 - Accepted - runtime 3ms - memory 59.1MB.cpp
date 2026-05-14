#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int k_small = nums.size() - k;
        int left = 0, right = nums.size() - 1;
        int pivot_counter;

        // At worst case the algo is O(N^2) when pivot value is probably same and plenty are there.
        // To avoid this case, count pivot points and see if ksmall falls in the range or not.

        while (left < right) {
            pivot_counter = 0;
            int index = partition(nums, left, right, pivot_counter);
            if (index == k_small || index >= k_small - pivot_counter + 1 && index <= k_small) {
                return nums[index];
            }
            if (index < k_small) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }

        return nums[right];
    }

    int partition(vector<int>& nums, int left, int right, int& pivot_counter) {
        if (left == right) return left;
        int pivot = left + rand() % (right - left + 1);
        pivot_counter = 0;

        swap(nums[pivot], nums[right]);
        int l = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < nums[right]) {
                swap(nums[l], nums[i]);
                l++;
            } else if (nums[i] == nums[right])
                pivot_counter++;
        }

        swap(nums[l], nums[right]);
        return l;
    }
};