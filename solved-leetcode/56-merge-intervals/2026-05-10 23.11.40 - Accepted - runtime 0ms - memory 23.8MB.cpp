class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int n = ans.size();
            if (ans[n - 1][1] >= intervals[i][0])
                ans[n - 1][1] = max(ans[n - 1][1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }

        return ans;
    }
};