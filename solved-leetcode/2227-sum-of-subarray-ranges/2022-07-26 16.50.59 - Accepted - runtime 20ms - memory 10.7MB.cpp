class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        long result=0;
        stack<int> st;
        
        // find subarrays where arr[mid] is minimum
        for(int i=0; i<= arr.size(); i++){
            while(!st.empty() && (i==arr.size() || arr[st.top()] > arr[i]) ){
                int mid = st.top();
                st.pop();
                
                int left = -1;
                if(!st.empty())
                    left = st.top();
                
                // here, mid - (left -1 ) + 1 = mid - left
                result -=  1l * arr[mid] * (mid-left) * (i - mid);
            }
            st.push(i);
        }
        
        st = stack<int>();
        
        // find subarrays where arr[mid] is maximum
        for(int i=0; i<= arr.size(); i++){
            while(!st.empty() && (i==arr.size() || arr[st.top()] < arr[i]) ){
                int mid = st.top();
                st.pop();
                
                int left = -1;
                if(!st.empty())
                    left = st.top();
                
                // here, mid - (left -1 ) + 1 = mid - left
                result +=  1l * arr[mid] * (mid-left) * (i - mid);
            }
            st.push(i);
        }
        
        
        return result;
    }
};