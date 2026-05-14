class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int low = newInterval[0];
        int high = newInterval[1];
        
        vector<vector<int>> ans;
        
        int index = 0;
        
        while(index < intervals.size() && intervals[index][1] < low){
            ans.push_back( intervals[index] );
            index++;
        }
        
        ans.push_back({low, high});
        if(index<intervals.size() && ans.back()[1] >= intervals[index][0]){
            ans.back()[0] = min( ans.back()[0], intervals[index][0]);
            ans.back()[1] = max( ans.back()[1], intervals[index][1]);
        }
        
         while(index < intervals.size() ){
             if(ans.back()[1] < intervals[index][0] ){
                 ans.push_back(intervals[index]);
             } else {
                 ans.back()[1] = max( ans.back()[1], intervals[index][1]);
             }
             index++;
         }
        
        return ans;
    }
};


static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);