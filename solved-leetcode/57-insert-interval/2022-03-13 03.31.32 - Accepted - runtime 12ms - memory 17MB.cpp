#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int low = newInterval[0];
        int high = newInterval[1];

        vector<vector<int>> ans;

        int index = 0;

        while (index < intervals.size() && intervals[index][1] < low) {
            ans.push_back(intervals[index]);
            index++;
        }

        ans.push_back({low, high});

        while (index < intervals.size()) {
            if (ans[ans.size() - 1][1] >= intervals[index][0]) {
                ans[ans.size() - 1][0] = min(ans[ans.size() - 1][0], intervals[index][0]);
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[index][1]);
            } else {
                ans.push_back(intervals[index]);
            }
            index++;
        }

        return ans;
    }
};