class NumArray {
public:
    NumArray(vector<int>& nums) {
        MaxVal = nums.size();
        tree = vector<int>(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            updateBIT(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        int old = sumRange(index, index);
        updateBIT(index + 1, val - old);
    }

    int sumRange(int left, int right) {
        int sum = query(right + 1);
        sum -= query(left);
        return sum;
    }

private:
    vector<int> tree;
    int MaxVal;

    void updateBIT(int idx, int val) {
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
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
