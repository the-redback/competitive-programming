class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }

    vector<vector<int>> result;
    vector<int> comb;

    void backtrack(int n, int k, int start) {
        if (comb.size() == k) {
            result.push_back(comb);
            return;
        }

        for (int i = start; i <= n; i++) {
            comb.push_back(i);
            backtrack(n, k, i + 1);
            comb.pop_back();
        }
        return;
    }
};
