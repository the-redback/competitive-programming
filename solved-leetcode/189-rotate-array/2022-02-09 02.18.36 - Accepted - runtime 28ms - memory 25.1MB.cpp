#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        k = k % nums.size();
        int count = 0;

        for (int start = 0; count < nums.size(); start++) {
            int next = start;
            int temp = nums[start];
            int hand = nums[start];
            do {
                next = (next + k) % nums.size();
                temp = nums[next];
                nums[next] = hand;
                hand = temp;
                count++;
            } while (next != start);
        }
    }
};