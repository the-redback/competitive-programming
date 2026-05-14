#include <vector>
#include <stack>

using namespace std;

int mod = 1000000007;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int dp[arr.size()];
        int total = 0;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if (st.empty())
                dp[i] = (arr[i] * (i + 1)) % mod;
            else
                dp[i] = (dp[st.top()] + arr[i] * (i - st.top())) % mod;

            total = (total + dp[i]) % mod;

            st.push(i);
        }
        return total;
    }
};