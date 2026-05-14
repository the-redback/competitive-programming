#include <iostream>
using namespace std;

class Solution {
private:
    unordered_map<string, bool> mp;

public:
    vector<string> generateParenthesis(int n) {
        N = n;
        rec("", 0, 0);
        return ans;
    }

    int N;
    vector<string> ans;

    void rec(string s, int open, int close) {
        if (s.size() == N * 2) {
            ans.push_back(s);
            return;
        }

        if (open < N) {
            s += "(";
            rec(s, open + 1, close);
            s.pop_back();
        }
        if (close < open) {
            s += ")";
            rec(s, open, close + 1);
            s.pop_back();
        }
    }
    // void Push(vector<string> &ans, string s){
    //     if(mp.find(s)==mp.end())
    //         ans.push_back(s);
    //     mp[s]=1;
    // }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);