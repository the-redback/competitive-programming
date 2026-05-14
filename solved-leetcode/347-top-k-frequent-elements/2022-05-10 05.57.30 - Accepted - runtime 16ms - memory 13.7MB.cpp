class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        unordered_map<int, int> mp;

        for (auto num : nums) {
            mp[num]++;
        }

        for (auto m : mp) {
            minheap.push({m.second, m.first});
            if (minheap.size() > k) minheap.pop();
        }

        vector<int> ans;
        while (!minheap.empty()) {
            ans.push_back(minheap.top().second);
            minheap.pop();
        }

        return ans;
    }
};