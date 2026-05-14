#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) break;
            i--;
        }

        for (int j = nums.size() - 1; i >= 0 && j >= i; j--) {
            if (nums[j] > nums[i]) {
                swap(nums[j], nums[i]);
                break;
            }
        }

        for (int j = i + 1, k = nums.size() - 1; j < k; j++, k--) {
            swap(nums[j], nums[k]);
        }

        return;
    }
};

// ref: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

// 5 2 4 6 5 5 3 2