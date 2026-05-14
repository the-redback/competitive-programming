#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dist, i});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto p = pq.top();
            ans.push_back(points[p.second]);
            pq.pop();
        }
        return ans;
    }
};