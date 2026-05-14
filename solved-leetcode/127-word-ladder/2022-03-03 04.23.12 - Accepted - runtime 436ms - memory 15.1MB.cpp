class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int>mp;

        for(int i=0;i<wordList.size();i++){
            mp[wordList[i]]=i;
        }
        
        vector<int>visited(wordList.size());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            for(int i=0;i<tp.first.size();i++){
                string str=tp.first;
                for(int k='a';k<='z';k++){
                    str[i]=k;
                    if(mp.find(str)==mp.end()|| visited[mp[str]])
                        continue;
                    if(str==endWord)
                        return tp.second+1;
                    visited[mp[str]]=1;
                    q.push({str,tp.second+1});
                }
            }
        }
        return 0;
    }
    
};

// Fast I/O; 4 ms.
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
