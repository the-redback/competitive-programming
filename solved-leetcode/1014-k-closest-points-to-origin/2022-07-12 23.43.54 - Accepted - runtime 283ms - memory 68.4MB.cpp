#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            auto p = points[i];
            int dist = p[0] * p[0] + p[1] * p[1];
            pq.push({dist, i});

            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(points[p.second]);
        }
        return ans;
    }
};