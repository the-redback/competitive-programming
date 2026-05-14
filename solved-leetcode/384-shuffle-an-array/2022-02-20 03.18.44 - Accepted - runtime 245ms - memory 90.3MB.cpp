class Solution {
private: 
    vector<int>original;
    vector<int>sf;
    
public:
    Solution(vector<int>& nums) {
        original=nums;
        sf=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        for(int i=sf.size()-1;i>=0;i--){
            int in=rand()%(i+1);
            swap(sf[i],sf[in]);
        }
        return sf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */