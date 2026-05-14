#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int N;
    unordered_map<string, vector<string>> prefix;

    void buildPrefix(string& word) {
        string s = "";
        prefix[s].push_back(word);

        for (auto ch : word) {
            s += ch;
            prefix[s].push_back(word);
        }
        return;
    }

    void backtrack(vector<string>& word_square, int i, vector<vector<string>>& ans) {
        if (i == N) {
            ans.push_back(word_square);
            return;
        }

        string curr_prefix = "";
        for (auto w : word_square) {
            curr_prefix += w[i];
        }

        for (auto w : prefix[curr_prefix]) {
            word_square.push_back(w);
            backtrack(word_square, i + 1, ans);
            word_square.pop_back();
        }

        return;
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        N = words[0].size();
        vector<vector<string>> ans;
        vector<string> word_square;

        for (auto word : words) {
            buildPrefix(word);
        }

        backtrack(word_square, 0, ans);

        return ans;
    }
};