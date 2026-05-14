#include <stack>

using namespace std;

int mod = 1000000007;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long res = 0;
        int n = arr.size(), mid, left;
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && arr[st.top()] > (i == n ? -2e9 : arr[i])) {
                mid = st.top(), st.pop();
                left = st.empty() ? -1 : st.top();
                res = (res + 1ll * arr[mid] * (i - mid) * (mid - left)) % mod;
            }
            st.push(i);
        }

        return res;
    }
};
