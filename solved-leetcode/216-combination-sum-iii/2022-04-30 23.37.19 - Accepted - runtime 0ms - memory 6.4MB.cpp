class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, n, 1);
        return result;
    }
    
    vector<vector<int>>result;
    vector<int> comb;
    
    void backtrack(int k, int n, int remain, int start){
        if(remain <= 0){
            if(remain == 0 && comb.size() == k) 
                result.push_back(comb);
            return;
        }
        
        for(int i=start; i<= 9; i++){
            if(remain - i >= 0){
                comb.push_back(i);
                backtrack(k, n, remain-i, i+1);
                comb.pop_back();                
            }
        }
        return;
    }
};