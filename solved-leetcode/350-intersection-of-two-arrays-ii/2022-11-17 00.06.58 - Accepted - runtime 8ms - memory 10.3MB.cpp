#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (auto num : nums1) {
            mp[num]++;
        }

        vector<int> result;
        for (auto num : nums2) {
            if (mp.find(num) != mp.end() && mp[num] > 0) {
                mp[num]--;
                result.push_back(num);
            }
        }
        return result;
    }
};