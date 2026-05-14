#include <vector>
using namespace std;

// Case 1;
// ------- |
//         | +++++++ (new interval {low, high})
//  low is higher than array intervals.

// Case 2:
//         |  -------
// +++++++ |
// high is lower than array intervals. So, to determine that ranges have overlapped, flip condition (after ensuring 1st
// conditon has met).

// case 3:
//        -------
//    +++++++

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

        // 2nd case, flipped condition.
        while (i < intervals.size() && high >= intervals[i][0]) {
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
