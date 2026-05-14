class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n);
        par = vector<int>(n, -1);
        
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        par[0]=0;
        if(!rec(0))
            return false;
        
        for(int i=0; i<n; i++)
            if(par[i]  == -1)
                return false;
        
        return true;
    }
    
    
    vector<int>par;
    vector<vector<int>>graph;
    bool ans;
    
    bool rec(int u){
        for(auto v: graph[u]){
            if(v  ==  par[u])
                continue;
            if(par[v]!=-1)
                return false;
            par[v]=u;
            if(!rec(v))
                return false;
        }
        return true;
    }
};