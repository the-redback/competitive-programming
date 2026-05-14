#include <iostream>
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

        rev(nums, 0, len - 1);
        rev(nums, 0, k - 1);
        rev(nums, k, len - 1);

        return;
    }
};
