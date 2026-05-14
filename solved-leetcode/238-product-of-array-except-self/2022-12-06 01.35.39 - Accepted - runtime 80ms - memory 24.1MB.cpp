class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>answer(nums.size());
        
        answer[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            answer[i]=answer[i-1]*nums[i];
        }
        
        // answer[nums.size()-1] = answer[nums.size()-2];
        int right=1;
        for(int i=nums.size()-1; i>0; i--){
            answer[i] = right * answer[i-1];
            right*=nums[i];
        }
        
        answer[0]=right;
        
        return answer;
    }
};