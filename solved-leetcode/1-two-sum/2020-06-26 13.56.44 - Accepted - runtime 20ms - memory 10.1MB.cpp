#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) 
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }
            mp[nums[i]]=i;
            
        }
        return ans;
    }
};