#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int n : nums) {
            pq.push(n);

            if (pq.size() > nums.size() - k + 1) {
                pq.pop();
            }
        }

        return pq.top();
    }
};