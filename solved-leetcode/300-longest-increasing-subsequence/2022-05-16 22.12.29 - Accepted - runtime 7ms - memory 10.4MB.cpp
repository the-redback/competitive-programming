#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        for (auto num : nums) {
            if (ans.empty() || ans.back() < num)
                ans.push_back(num);
            else {
                int in = b_search(ans, num);
                ans[in] = num;
            }
        }

        return ans.size();
    }

    int b_search(vector<int>& ans, int n) {
        int low = 0;
        int high = ans.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;

            if (ans[mid] == n) return mid;

            if (ans[mid] < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};