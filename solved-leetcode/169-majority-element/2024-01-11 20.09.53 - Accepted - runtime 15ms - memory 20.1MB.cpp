class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // https://leetcode.com/problems/majority-element/solutions/3676530/3-method-s-beats-100-c-java-python-beginner-friendly

        int count = 0;
        int candidate = 0;

        for(int num : nums){
            if(count == 0){
                candidate = num;
            }

            if(num == candidate){
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};