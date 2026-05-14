class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        k = k % nums.size();
        int count = 0;

        for (int start = 0; count < nums.size(); start++) {
            int next = (start + k) % nums.size();
            int temp = nums[next];
            int hand = nums[start];
            nums[next] = hand;
            hand = temp;
            count++;
            while (next != start) {
                next = (next + k) % nums.size();
                int temp = nums[next];
                nums[next] = hand;
                hand = temp;
                count++;
            }
        }
    }
};