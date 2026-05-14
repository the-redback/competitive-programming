bool comp(vector<int>&u, vector<int>&v) { 
        return u[1] < v[1];
}

class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        int ans = 1;

        sort(points.begin(), points.end(), comp); 

        int shotx = points[0][1];
        for(int i = 0; i<points.size(); i++){
            if(shotx >= points[i][0] && shotx <= points[i][1])
                continue;
            
            shotx = points[i][1];
            ans++;
        }
        
        return ans;
    }
};