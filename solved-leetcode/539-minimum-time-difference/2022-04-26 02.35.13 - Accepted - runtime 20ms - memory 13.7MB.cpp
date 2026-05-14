class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int>t;
        for(auto s: timePoints){
            t.push_back(stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,2)));
        }
        int res=24*60;
        
        sort(t.begin(), t.end());
        t.push_back(t[0]+res);
        
        for(int i=0; i<t.size()-1; i++){
            res=min(res, t[i+1] - t[i]);
            if(res==0)
                return res;
        }
        
        return res;
    }
};