#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ones = 0, zero = 0, mx = 0;
        int a[2] = {0};

        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]]++;

            while (start <= i && a[0] > k) {
                a[nums[start]]--;
                start++;
            }
            mx = max(mx, a[0] + a[1]);
        }

        return mx;
    }
};