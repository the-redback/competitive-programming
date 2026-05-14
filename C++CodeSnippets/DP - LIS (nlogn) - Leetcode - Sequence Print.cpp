#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> lisLength;

public:
    int b_search(vector<int>& ans, int n) {
        int low = 0;
        int high = ans.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;
            if (ans[mid] == n) {
                return mid;
            }

            if (ans[mid] < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> ans;
        lisLength.assign(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++) {
            if (ans.empty() || ans.back() < nums[i]) {
                ans.push_back(nums[i]);
                lisLength[i] = ans.size();
            } else {
                int in = b_search(ans, nums[i]);
                ans[in] = nums[i];
                lisLength[i] = in + 1;
            }
        }

        return ans.size();
    }

    vector<int> buildLIS(vector<int>& nums) {
        vector<int> sequence;
        int n = nums.size();
        if (n == 0) return sequence;

        int maxLen = 0;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (lisLength[i] > maxLen) {
                maxLen = lisLength[i];
                idx = i;
            }
        }

        sequence.push_back(nums[idx]);
        int currentTargetLen = maxLen - 1;

        for (int i = idx - 1; i >= 0; i--) {
            if (nums[i] < nums[idx] && lisLength[i] == currentTargetLen) {
                sequence.push_back(nums[i]);
                idx = i;
                currentTargetLen--;
            }
        }

        reverse(sequence.begin(), sequence.end());
        return sequence;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = sol.lengthOfLIS(nums);
    cout << "LIS Length: " << length << '\n';

    vector<int> lis = sol.buildLIS(nums);
    cout << "LIS: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << '\n';

    return 0;
}

/*
Sample Input:
nums = [10, 9, 2, 5, 3, 7, 101, 18]

Sample Output:
LIS Length: 4
LIS: 2 3 7 18
*/
