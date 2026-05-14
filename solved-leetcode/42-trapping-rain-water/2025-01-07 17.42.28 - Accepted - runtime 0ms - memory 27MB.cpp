#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> st;

        int i = 0;
        while (i < n) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }

                int dist = i - st.top() - 1;
                int bounded_height = min(height[st.top()], height[i]) - height[top];
                ans += dist * bounded_height;
            }
            st.push(i++);
        }
        return ans;
    }
};