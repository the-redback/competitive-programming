class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        N=words[0].size();
        
        buildprefix(words);
        
        vector<vector<string>>ans;
        vector<string> ws;
        
        backtrack(ws, 0, ans);
        
        return ans;
    }

    
    
private:
    int N;
    unordered_map<string,vector<string>>mp;
    
    void backtrack(vector<string> &wordSquare, int step, vector<vector<string>> &ans){
        if(step == N){
            ans.push_back(wordSquare);
            return;
        }
        
        string prefix = "";
        for(auto word: wordSquare){
            prefix += word[step];
        }
        
        for(auto word : mp[prefix]){
            wordSquare.push_back(word);
            backtrack(wordSquare, step+1, ans);
            wordSquare.pop_back();
        }
        return;
    }
    
    void buildprefix(vector<string> &words){
        for(auto word : words){
            string s = "";
            mp[s].push_back(word);
            
            for(auto ch : word){
                s += ch;
                mp[s].push_back(word);
            }
        }
    }
};


static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);