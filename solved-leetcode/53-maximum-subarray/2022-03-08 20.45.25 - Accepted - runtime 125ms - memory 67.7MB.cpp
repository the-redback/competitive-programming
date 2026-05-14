class Solution {
public:
    int maxSubArray(vector<int>& nums) { return findBest(nums, 0, nums.size() - 1); }

private:
    int findBest(vector<int>& nums, int l, int r) {
        if (l > r) return INT_MIN;

        int mid = (l + r) / 2;

        int curr = 0;
        int bestleft = 0;
        int bestright = 0;

        for (int i = mid - 1; i >= l; i--) {
            curr += nums[i];
            bestleft = max(bestleft, curr);
        }

        curr = 0;
        for (int i = mid + 1; i <= r; i++) {
            curr += nums[i];
            bestright = max(bestright, curr);
        }

        int best = nums[mid] + bestleft + bestright;

        int leftHalf = findBest(nums, l, mid - 1);
        int rightHalf = findBest(nums, mid + 1, r);

        return max(best, max(leftHalf, rightHalf));
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
