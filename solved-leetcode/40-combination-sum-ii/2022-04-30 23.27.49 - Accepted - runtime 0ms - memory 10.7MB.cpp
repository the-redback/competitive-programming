#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return result;
    }

    vector<vector<int>> result;
    vector<int> comb;

    void backtrack(vector<int>& candidates, int remain, int start) {
        if (remain <= 0) {
            if (remain == 0) result.push_back(comb);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i != start && candidates[i] == candidates[i - 1]) continue;
            if (remain - candidates[i] >= 0) {
                comb.push_back(candidates[i]);
                backtrack(candidates, remain - candidates[i], i + 1);
                comb.pop_back();
            }
        }
        return;
    }
};