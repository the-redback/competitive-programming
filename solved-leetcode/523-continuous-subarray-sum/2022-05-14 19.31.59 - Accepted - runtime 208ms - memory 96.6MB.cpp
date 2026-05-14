#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = -1;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            curr %= k;

            if (mp.find(curr) != mp.end()) {
                if (i - mp[curr] >= 2) return true;
            } else {
                mp[curr] = i;
            }
        }
        return false;
    }
};