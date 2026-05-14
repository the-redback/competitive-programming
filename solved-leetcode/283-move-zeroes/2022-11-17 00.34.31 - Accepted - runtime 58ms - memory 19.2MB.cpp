class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        int i=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]==0){
                cnt++;
                continue;
            }
            nums[i]=nums[j];
            i++;
        }
        while(cnt>0){
            nums[i]=0;
            i++;
            cnt--;
        }
        return;
    }
};