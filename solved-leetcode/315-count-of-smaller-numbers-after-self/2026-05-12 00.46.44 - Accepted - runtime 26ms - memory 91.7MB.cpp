class Solution {
public:
    vector<int> tree;
    int MaxVal;

    void update(int idx, int val) {
        while (idx <= MaxVal) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
        return;
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4 + 10;
        MaxVal = 2e4 + 20;
        tree.resize((MaxVal + 1));
        vector<int> ans(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            int pos = nums[i] + offset;
            ans[i] = query(pos - 1);
            update(pos, 1);
        }

        return ans;
    }
};
