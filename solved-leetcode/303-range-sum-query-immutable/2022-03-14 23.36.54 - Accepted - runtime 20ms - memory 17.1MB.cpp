#include <iostream>
using namespace std;

class NumArray {
    vector<int> pre;

public:
    NumArray(vector<int>& nums) {
        pre = nums;
        for (int i = 1; i < nums.size(); i++) {
            pre[i] += pre[i - 1];
        }
    }

    int sumRange(int left, int right) {
        int ans = pre[right];
        if (left > 0) ans -= pre[left - 1];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
