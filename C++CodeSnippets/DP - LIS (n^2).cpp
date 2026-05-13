#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> dp;

int LIS(int u) {
    int& tc = dp[u];
    if (tc != -1) {
        return tc;
    }

    tc = 1;
    for (int i = u + 1; i < nums.size(); i++) {
        if (nums[i] > nums[u]) {
            tc = max(tc, LIS(i) + 1);
        }
    }
    return tc;
}

int lengthOfLIS() {
    dp.assign(nums.size(), -1);
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans = max(ans, LIS(i));
    }
    return ans;
}

int main() {
    nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS() << '\n';
    return 0;
}

/*
Sample Input:
nums = [10, 9, 2, 5, 3, 7, 101, 18]

Sample Output:
4

Explanation:
One longest increasing subsequence is:
[2, 3, 7, 101]
*/