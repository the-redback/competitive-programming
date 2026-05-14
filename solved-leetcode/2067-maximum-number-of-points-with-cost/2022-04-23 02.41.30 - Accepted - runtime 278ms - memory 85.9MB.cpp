#include <vector>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size(), c = points[0].size();

        vector<long long> pre(c);
        vector<long long> left(c, 0), right(c, 0), cur(c, 0);

        for (int j = 0; j < c; j++) pre[j] = points[0][j];

        for (int i = 0; i < r - 1; i++) {
            left[0] = pre[0];
            right[c - 1] = pre[c - 1];

            for (int j = 1; j < c; j++) {
                left[j] = max(left[j - 1] - 1, pre[j]);
            }

            for (int j = c - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, pre[j]);
            }

            for (int j = 0; j < c; j++) cur[j] = points[i + 1][j] + max(left[j], right[j]);

            pre = cur;
        }

        long long ans = 0;

        for (int j = 0; j < c; j++) {
            ans = max(ans, pre[j]);
        }

        return ans;
    }
};