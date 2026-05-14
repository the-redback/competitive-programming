class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        buildprefix(words);
        N = words[0].size();
        //         for(auto words: mp){
        //             for(auto s: words.second){
        //                 cout<< words.first << " " << s << " ";
        //             }
        //             cout << endl;
        //         }

        vector<vector<string>> ans;
        vector<string> ws;
        backtrack(ws, 0, ans);
        return ans;
    }

private:
    int N;
    map<string, vector<string>> mp;

    void backtrack(vector<string>& wordSquare, int step, vector<vector<string>>& ans) {
        if (step == N) {
            ans.push_back(wordSquare);
            return;
        }

        string prefix = "";
        for (auto word : wordSquare) {
            prefix += word[step];
        }

        for (auto word : mp[prefix]) {
            wordSquare.push_back(word);
            backtrack(wordSquare, step + 1, ans);
            wordSquare.pop_back();
        }
        return;
    }

    void buildprefix(vector<string>& words) {
        for (auto word : words) {
            string s = "";
            mp[s].push_back(word);

            for (auto ch : word) {
                s += ch;
                mp[s].push_back(word);
            }
        }
    }
};