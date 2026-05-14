class Solution {
public:
    unordered_map<char, char> sub_numbers = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    vector<string> ans;
    int N;

    void rec(string curr) {
        if (curr.size() == N) {
            ans.push_back(curr);
            return;
        }

        for (auto [u, v] : sub_numbers) {
            if (curr.size() + 2 == N && u == '0') continue;
            rec(u + curr + v);
        }

        return;
    }

    vector<string> findStrobogrammatic(int n) {
        N = n;
        if (n % 2 == 0) {
            rec("");
        } else {
            rec("0");
            rec("1");
            rec("8");
        }

        return ans;
    }
};