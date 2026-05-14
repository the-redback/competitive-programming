class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int sum=0;
        int mx=INT_MIN;
        for(auto num:nums){
            mx=max(mx,num);
            sum+=num;
        }
        
        int low=mx, high=sum;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(search(nums,mid)<=m){
                ans=mid;
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        return ans;
        
    }
    
    int search(vector<int> &nums, int mid){
        int cnt=0;
        int curr=0;
        for(auto num:  nums){
            if(curr+num > mid){
                cnt++;
                curr=num;
                continue;
            }
            curr+=num;
        }
        return cnt+1;
    }
};