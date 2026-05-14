class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ones=0, zero=0, mx=0;
    
        int start=0;
        for(int i=0 ;i< nums.size(); i++){
            if(nums[i]==1)
                ones++;
            else
                zero++;
            
            while(start <=i && zero > k){
                if(nums[start])
                    ones--;
                else
                    zero--;
                start++;
            }
            mx=max(mx, zero+ones);
        }
        
        return mx;
    }
};