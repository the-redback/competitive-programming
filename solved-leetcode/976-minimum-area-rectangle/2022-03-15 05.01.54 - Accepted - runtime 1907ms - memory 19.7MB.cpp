class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        for(auto &p: points){
            mp[{p[0], p[1]}]=true;
        }
        
        int res=INT_MAX;
        for(auto &a: points){
            for(auto &b: points){
                if(a[0]== b[0] || a[1] == b[1])
                    continue;
                
                int mnx=min(a[0], b[0]);
                int mxx=max(a[0], b[0]);
                int mny=min(a[1], b[1]);
                int mxy=max(a[1], b[1]);
                if(mp.find({mnx, mny})!= mp.end() && 
                  mp.find({mnx, mxy})!= mp.end() && 
                  mp.find({mxx, mny})!= mp.end() && 
                  mp.find({mxx, mxy})!= mp.end()) {
                    int area=(mxx-mnx) * (mxy-mny);
                    res=min(res,area);
                }
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }
    
map<pair<int, int>, bool>mp;
};