class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 1;
        for (int j = 1; i < nums.size() && j < nums.size(); j++) {
            if (nums.at(j) != nums.at(j - 1)) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};