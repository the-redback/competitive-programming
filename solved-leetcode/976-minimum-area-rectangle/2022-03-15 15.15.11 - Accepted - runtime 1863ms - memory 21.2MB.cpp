class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<int> setX, setY;
        for(auto &p: points) {
            setX.insert(p[0]);
            setY.insert(p[1]);
        } 
        
        if(setX.size() == points.size() || setY.size() == points.size() )
            return 0;
        
        
        for(auto &p: points){
            mp[p[0]][p[1]]=true;
        }
        
        int res=INT_MAX;
        for(auto &a: points){
            for(auto &b: points){
                if(a[0]== b[0] || a[1] == b[1])
                    continue;
                
                int ax=a[0];
                int ay=b[1];
                int bx=b[0];
                int by=a[1];
                if(mp[ax].find(ay)!= mp[ax].end() && 
                  mp[bx].find(by)!= mp[bx].end()) {
                    int area= abs((ax - bx) * (ay - by));
                    res=min(res,area);
                }
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }
    
    unordered_map<int, unordered_map<int, bool>>mp;
};


static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
