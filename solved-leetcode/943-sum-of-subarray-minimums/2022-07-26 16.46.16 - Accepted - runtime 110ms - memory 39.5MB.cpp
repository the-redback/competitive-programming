int mod = 1000000007;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int result=0;
        stack<int> st;
        
        for(int i=0; i<= arr.size(); i++){
            while(!st.empty() && (i==arr.size() || arr[st.top()] > arr[i]) ){
                int mid = st.top();
                st.pop();
                
                int left = -1;
                if(!st.empty())
                    left = st.top();
                
                // here, mid - (left -1 ) + 1 = mid - left
                result = (result + (1ll * arr[mid] * ((mid-left) * (i - mid)) % mod  ) % mod )%mod;
            }
            st.push(i);
        }
        
        return result;

    }
};

// res = sum(A[i] * f(i))
// where f(i) is the number of subarrays,
// in which A[i] is the minimum.

// left - mid : a[mid] is single minimum
// mid - right : a[mid] is first minimum

// 