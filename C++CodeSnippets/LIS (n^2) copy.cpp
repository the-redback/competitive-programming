#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<int> dp;

int LDS(int u) {
    int& tc = dp[u];

    if (tc != -1) {
        return tc;
    }

    tc = 1;
    for (int i = u + 1; i < nums.size(); i++) {
        if (nums[i] <= nums[u]) {
            tc = max(tc, 1 + LDS(i));
        }
    }
    return tc;
}

int main() {
    nums = {389, 207, 155, 300, 299, 170, 158, 65};

    int n = nums.size();
    dp.assign(n, -1);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, LDS(i));
    }
    cout << ans << '\n';
    return 0;
}