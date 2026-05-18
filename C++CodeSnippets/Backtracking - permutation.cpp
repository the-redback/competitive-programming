#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> comb;
    vector<int> taken;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        taken.assign(nums.size(), 0);

        backtrack(nums);
        return result;
    }

    void backtrack(vector<int>& nums) {
        if (comb.size() == nums.size()) {
            result.push_back(comb);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (taken[i])
                continue;

            // Skip duplicate permutations
            if (i > 0 && nums[i] == nums[i - 1] && !taken[i - 1])
                continue;

            taken[i] = 1;
            comb.push_back(nums[i]);
            backtrack(nums);
            comb.pop_back();
            taken[i] = 0;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 2, 3, 4, 2};

    vector<vector<int>> ans = sol.permuteUnique(nums);
    cout<<ans.size()<<endl;

    for (auto& vec : ans) {
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}