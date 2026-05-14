class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return result;
    }
    
    vector<vector<int>>result;
    vector<int> comb;
    
    void backtrack(vector<int>& candidates, int remain, int start){
        if(remain <= 0){
            if(remain == 0) 
                result.push_back(comb);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++){
            comb.push_back(candidates[i]);
            backtrack(candidates, remain-candidates[i], i);
            comb.pop_back();
        }
        return;
    }
};