#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        k = nums.size() - k + 1;
        for (auto n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};