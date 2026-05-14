#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find longest suffix
        int suffix;
        for (suffix = nums.size() - 1; suffix > 0; suffix--) {
            if (nums[suffix] > nums[suffix - 1]) break;
        }

        // swap pivot with rightmost bigger value
        int pivot = -1;
        if (suffix != 0) {
            pivot = suffix - 1;
            for (int i = nums.size() - 1; i > pivot; i--) {
                if (nums[pivot] < nums[i]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }

        // reverse post pivot part
        for (int i = pivot + 1, j = nums.size() - 1; i < j; i++, j--) swap(nums[i], nums[j]);
    }
};

// ref: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm