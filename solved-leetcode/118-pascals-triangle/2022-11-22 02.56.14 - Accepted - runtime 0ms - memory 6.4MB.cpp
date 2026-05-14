#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};

        for (int i = 1; i < numRows; i++) {
            vector<int> v;
            v.push_back(1);
            for (int j = 1; j < i; j++) {
                int tmp = ans[i - 1][j - 1] + ans[i - 1][j];
                v.push_back(tmp);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};