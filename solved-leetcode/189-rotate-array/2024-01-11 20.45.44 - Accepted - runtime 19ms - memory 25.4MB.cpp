class Solution {
    void rev(vector<int>& nums,int low,int high){
        while(low<high){
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;

        if(k == 0)
         return;

        for(int i=0, j= len-k-1; i < j; i++, j--)
            swap(nums[i],nums[j]);
        
        for(int i=len-k, j= len-1; i < j; i++, j--)
            swap(nums[i],nums[j]);
        
        for(int i=0, j= len-1; i < j; i++, j--)
            swap(nums[i],nums[j]);

        return; 
    }
};

// https://leetcode.com/problems/rotate-array/solutions/3506340/beats-100-3-line-solution-fully-most-optimised-code


// 1234567 , 3 => (1234) (567) => (4321) (765) => 567 1234

// 1234    567
// ----    ---
//   A      B
// AB = rev(A)rev(B) = A'B'
// rev(A'B')= BA 