class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> rates;

        for (int i = 0; i < n; i++) {
            rates.push_back({(double)wage[i] / quality[i], quality[i]});
        }

        sort(rates.begin(), rates.end());
        priority_queue<int> pq;
        int totalQuality = 0;
        double totalCost = (double)LLONG_MAX;

        for (auto rate : rates) {
            // the set needs to be k-1 to consider a new item
            pq.push(rate.second);
            totalQuality += rate.second;

            if (pq.size() > k) {
                totalQuality -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                totalCost = min(totalCost, rate.first * totalQuality);
            }
        }

        return totalCost;
    }
};