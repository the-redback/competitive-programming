class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> lo, hi;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                int out_num = nums[i - k];
                if (out_num <= *lo.rbegin())
                    lo.erase(lo.find(out_num));
                else
                    hi.erase(hi.find(out_num));
            }

            lo.insert(nums[i]);

            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));

            if (lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }

            if (i >= k - 1) {
                double cal = (double)*lo.rbegin();
                if (k % 2 == 0) {
                    cal = (cal + (double)*hi.begin()) / 2.0;
                }
                ans.push_back(cal);
            }
        }

        return ans;
    }
};
