#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size());
        stack<int> st;

        for (int k = 2 * nums.size() - 1; k >= 0; k--) {
            int i = k % nums.size();

            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            if (st.empty())
                result[i] = -1;
            else
                result[i] = nums[st.top()];
            st.push(i);
        }

        return result;
    }
};