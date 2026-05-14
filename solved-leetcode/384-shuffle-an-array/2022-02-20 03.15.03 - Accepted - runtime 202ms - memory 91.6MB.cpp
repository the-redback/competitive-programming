class Solution {
    private: vector<int>original;
public:
    Solution(vector<int>& nums) {
        srand(time(NULL));
        original=nums;
    }
    
    vector<int> reset() {
        vector<int> ans(original);
        return original;
    }
    
    vector<int> shuffle() {
        vector<int>ans(original);
        int n=ans.size();
        for(int i=0;i<n;i++){
            int in=rand()%(n-i)+i;
            swap(ans[i],ans[in]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */