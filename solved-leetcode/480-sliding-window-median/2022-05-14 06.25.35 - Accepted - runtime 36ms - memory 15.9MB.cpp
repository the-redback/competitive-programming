#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> all(nums.begin(), nums.begin() + k);

        auto mid = next(all.begin(), k / 2);

        for (int i = k; i <= nums.size(); i++) {
            double cal = *mid;
            if (k % 2 == 0) {
                cal = (cal + *prev(mid)) / 2.0;
            }
            ans.push_back(cal);

            if (i == nums.size()) break;

            all.insert(nums[i]);

            if (nums[i] < *mid) mid--;

            if (nums[i - k] <= *mid) mid++;

            all.erase(all.lower_bound(nums[i - k]));
        }

        return ans;
    }
};

// 2 4 5 4 6  7 8 9
