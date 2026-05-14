class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>ans;
        if(nums.size()==0){
            pushRanges(ans,lower,upper);
            return ans;
        }
        if(nums[0]>lower)
            pushRanges(ans,lower,nums[0]-1);
        for(int i=1;i<nums.size();i++)
            if(nums[i]>nums[i-1]+1)
                pushRanges(ans,nums[i-1]+1,nums[i]-1);
        if(nums[nums.size()-1]<upper)
            pushRanges(ans,nums[nums.size()-1]+1,upper);
        
        return ans;
    }
    
    void pushRanges(vector<string>&ans, int l,int r){
        string str=to_string(l);
            if(r>l)
                str+="->"+to_string(r);
            ans.push_back(str);
    }
};