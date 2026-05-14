class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, int> > pq;

        for(int i = 0; i < points.size(); i++){
            auto p = points[i];
            int dist = p[0] * p[0] + p[1] * p[1];
            pq.push({dist, i});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};
