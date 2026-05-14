#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n;

        for (int i = 1; i < n;) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                i++;
                peak++;
                ans += peak;
            }

            int valley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                i++;
                valley++;
                ans += valley;
            }

            ans -= min(peak, valley);
        }

        return ans;
    }
};
