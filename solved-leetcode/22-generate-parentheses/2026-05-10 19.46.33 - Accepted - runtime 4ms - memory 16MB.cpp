#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;
    int N;

    void rec(string s, int open, int close) {
        if (s.size() == N * 2) {
            ans.push_back(s);
            return;
        }

        if (open < N) {
            rec(s + "(", open + 1, close);
        }

        if (close < open) {
            rec(s + ")", open, close + 1);
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        rec("", 0, 0);

        return ans;
    }
};