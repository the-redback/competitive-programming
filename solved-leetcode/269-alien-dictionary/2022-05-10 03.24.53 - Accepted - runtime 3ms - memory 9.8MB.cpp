class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int>mp;
        map<char, vector<char>>graph;
        
        for(auto word: words){
            for(auto ch: word){
                graph[ch]={};
                mp[ch]=0;
            }
        }
        
        for(int i=0; i<words.size()-1; i++){
            string s1=words[i];
            string s2=words[i + 1];
            
            if(s1.size() > s2.size() && s2 == s1.substr(0,s2.size()))
               return "";
            
            for(int j=0; j<min(s1.size(), s2.size()); j++){
                if(s1[j]!=s2[j]){
                    graph[s1[j]].push_back(s2[j]);
                    mp[s2[j]]++;
                    break;
                }
            }   
        }
        
        string ans="";
        unordered_map<char, bool> visited;

        for(auto ch: mp){
            if(visited.find(ch.first) != visited.end())
                continue;
            if( dfs(ch.first, graph, visited, ans))
                return "";
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool dfs(char u, map<char, vector<char>>& graph, unordered_map<char, bool>& visited, string &result){
        if(visited.find(u) != visited.end())
            return visited[u];
        
        visited[u] = true;
        
        for(auto v: graph[u]){
            if(dfs(v, graph, visited, result))
                return true;
        }
        result+=u;
        visited[u]=false;
        return false;
    }
};