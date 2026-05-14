#include <vector>

using namespace std;

class Solution {
public:
    vector<int> tree;

    void update(int node, int low, int high, int pos, int val) {
        if (pos < low || pos > high) return;
        if (low == pos && high == pos) {
            tree[node] += val;
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
        if (qlow > high || qhigh < low) return 0;
        if (qlow <= low && qhigh >= high) return tree[node];

        int left = node * 2;
        int right = left + 1;
        int mid = (low + high) / 2;

        int q1 = query(left, low, mid, qlow, qhigh);
        int q2 = query(right, mid + 1, high, qlow, qhigh);

        return q1 + q2;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;
        int MaxVal = 2e4;
        tree.resize(4 * (MaxVal + 1));
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int pos = nums[i] + offset;
            ans[i] = query(1, 0, MaxVal, 0, pos - 1);
            update(1, 0, MaxVal, pos, 1);
        }

        return ans;
    }
};