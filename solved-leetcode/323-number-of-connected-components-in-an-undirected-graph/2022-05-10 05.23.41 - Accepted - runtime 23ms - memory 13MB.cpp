class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        size = vector<int>(n);
        for(int i=0; i<n; i++)
            root.push_back(i);
        
        int cnt=n;
        for(auto e: edges){
            int u=find(e[0]);
            int v=find(e[1]);
            
            if(u != v){
                cnt--;
                Union(u, v);
            }
        }
        return cnt;
    }
    
    vector<int>root;
    vector<int>size;
    
    int find(int u){
        if(u != root[u])
            root[u]=find(root[u]);
        return root[u];
    }
    
    void Union(int u, int v){
        if(size[u] > size[v]){
            root[v]=u;
            size[u]+=size[v];
        } else {
            root[u]=v;
            size[v]+=size[u];
        }
    }
    
};