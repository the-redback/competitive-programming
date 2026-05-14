#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<double> distances;
        vector<int> remaining;
        double low = 0, high = 0;
        for (int i = 0; i < points.size(); i++) {
            double dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distances.push_back(dist);
            remaining.push_back(i);
            high = max(high, dist);
        }

        vector<vector<int>> ans;
        while (k) {
            double mid = low + (high - low) / 2;
            vector<vector<int>> result(2);
            splitdistances(remaining, distances, mid, result);

            vector<int>& closer = result[0];
            vector<int>& farther = result[1];

            if (closer.size() <= k) {
                k -= closer.size();
                for (auto index : closer) {
                    ans.push_back(points[index]);
                }
                remaining.swap(farther);
                low = mid + 1;
            } else {
                high = mid - 1;
                remaining.swap(closer);
            }
        }
        return ans;
    }

    void splitdistances(vector<int>& remaining, vector<double>& distances, double mid, vector<vector<int>>& result) {
        vector<int>& closer = result[0];
        vector<int>& farther = result[1];
        for (auto index : remaining) {
            if (distances[index] <= mid)
                closer.push_back(index);
            else
                farther.push_back(index);
        }

        return;
    }
};