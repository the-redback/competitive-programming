#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

class Solution {
    void rev(vector<int>& nums, int low, int high) {
        while (low < high) {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int len = nums.size();
        k = k % len;

        if (k == 0) return;

        rev(nums, 0, len - k - 1);
        rev(nums, len - k, len - 1);
        rev(nums, 0, len - 1);

        return;
    }
};

// https://leetcode.com/problems/rotate-array/solutions/3506340/beats-100-3-line-solution-fully-most-optimised-code

// 1234567 , 3 => (1234) (567) => (4321) (765) => 567 1234

// 1234    567
// ----    ---
//   A      B
// AB = rev(A)rev(B) = A'B'
// rev(A'B')= BA