#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int b_search(vector<int> &ans, int n) {
        int low = 0;
        int high = ans.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;
            if (ans[mid] == n)
                return mid;
            if (ans[mid] < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> ans;

        for (auto num: nums) {
            if (ans.empty() || ans.back() < num)
                ans.push_back(num);
            else {
                int in = b_search(ans, num);
                ans[in] = num;
            }
        }

        return ans.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = sol.lengthOfLIS(nums);
    cout << "LIS Length: " << length << '\n';
    return 0;
}

/*
Sample Input:
nums = [10, 9, 2, 5, 3, 7, 101, 18]

Sample Output:
LIS Length: 4
LIS: 2 3 7 18
*/
