#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int low = intervals[0][0];
        int high = intervals[0][1];

        vector<vector<int>> ans;

        for (int i = 1; i < intervals.size(); i++) {
            auto interval = intervals[i];

            if (interval[0] > high) {
                ans.push_back({low, high});
                low = interval[0];
                high = interval[1];
            } else {
                high = max(high, interval[1]);
            }
        }
        ans.push_back({low, high});

        return ans;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);