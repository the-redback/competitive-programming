class NumArray {
private:
    vector<int> tree;
    int N;

    void init(int node, int low, int high, vector<int>& nums) {
        if (low == high) {
            tree[node] = nums[low - 1];
            return;
        }

        int left = node * 2;
        int right = left + 1;
        int mid = (low + high) / 2;

        init(left, low, mid, nums);
        init(right, mid + 1, high, nums);
        tree[node] = tree[left] + tree[right];
    }

    void update(int node, int low, int high, int pos, int val) {
        if (pos > high || pos < low)
            return;

        if (low == pos && high == pos) {
            tree[node] = val;
            return;
        }

        int left = node * 2;
        int right = left + 1;
        int mid = (low + high) / 2;

        update(left, low, mid, pos, val);
        update(right, mid + 1, high, pos, val);
        tree[node] = tree[left] + tree[right];
    }

    int query(int node, int low, int high, int qlow, int qhigh) {
        if (qlow > high || qhigh < low)
            return 0;
        if (qlow <= low && qhigh >= high)
            return tree[node];

        int left = node * 2;
        int right = left + 1;
        int mid = (low + high) / 2;

        int q1 = query(left, low, mid, qlow, qhigh);
        int q2 = query(right, mid + 1, high, qlow, qhigh);
        return q1 + q2;
    }

public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        tree.resize(4 * N);
        init(1, 1, N, nums);
    }

    void update(int index, int val) {
        update(1, 1, N, index + 1, val);
    }

    int sumRange(int left, int right) {
        return query(1, 1, N, left + 1, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */