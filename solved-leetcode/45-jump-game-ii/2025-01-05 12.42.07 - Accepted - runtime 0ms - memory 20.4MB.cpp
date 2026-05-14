class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int stepBegin = 0, stepEnd = 0;

        for(int i=0; i<nums.size()-1; i++) {
            stepEnd = max(stepEnd, i+nums[i]);

            if(i == stepBegin){
                jumps++;
                stepBegin = stepEnd;
            }
        }

        return jumps;
    }
};