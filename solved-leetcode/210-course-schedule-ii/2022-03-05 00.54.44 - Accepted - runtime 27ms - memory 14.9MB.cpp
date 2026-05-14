class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        flag=0;
        vector<int>ans;
        vector<vector<int>>g(numCourses,vector<int>());
        memset(visit,-1,sizeof(visit));
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(visit[i]==-1)
                dfs(g,i,ans);
        }
        if(flag==1)
            return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
    int visit[2002];
    int flag;
    
    void dfs(vector<vector<int>>&g, int u, vector<int>&ans ){
        if(flag)
            return;
        visit[u]=0;
        for(auto v: g[u]){
            if(visit[v]==-1)
                dfs(g,v,ans);
            else if(visit[v]==0)
            {
                flag=1;
                return;
            }
        }
        visit[u]=1;
        ans.push_back(u);
    }
    
};