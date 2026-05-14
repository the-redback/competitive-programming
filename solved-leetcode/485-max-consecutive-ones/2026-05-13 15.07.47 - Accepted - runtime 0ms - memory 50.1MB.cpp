#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = 0;

        for (auto n : nums) {
            if (n != 1)
                count = 0;
            else
                ans = max(ans, ++count);
        }

        return ans;
    }
};