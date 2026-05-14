class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    vector<vector<int>> result;
    vector<int> comb;

    void backtrack(vector<int>& candidates, int start) {
        result.push_back(comb);
        for (int i = start; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            backtrack(candidates, i + 1);
            comb.pop_back();
        }
        return;
    }
};