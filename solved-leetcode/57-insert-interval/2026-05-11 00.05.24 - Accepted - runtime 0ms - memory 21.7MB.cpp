#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int low = newInterval[0];
        int high = newInterval[1];

        vector<vector<int>> ans;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < low) {
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= high) {
            low = min(low, intervals[i][0]);
            high = max(high, intervals[i][1]);
            i++;
        }

        ans.push_back({low, high});

        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};