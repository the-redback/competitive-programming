class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>>workers;
        for(int i=0;i<quality.size();i++)
            workers.push_back({(double) wage[i]/quality[i],(double) quality[i] });
        sort(workers.begin(),workers.end());
//         for(auto work: workers)
//             cout<<work[0]<< " "<<work[1]<<endl;
        double sum=0;
        double ans=DBL_MAX;
        priority_queue<double>pq;
        for(auto work:workers){
            pq.push(work[1]);
            sum+=work[1];
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                ans=min(ans,sum*work[0]);
        }
        return ans;
    }
};