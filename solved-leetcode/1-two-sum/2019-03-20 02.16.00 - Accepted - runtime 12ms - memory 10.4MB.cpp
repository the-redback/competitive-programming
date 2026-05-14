#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int k = target - nums[i];
            if (mp.find(k) != mp.end()) {
                ans.push_back(i);
                ans.push_back(mp[k]);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};