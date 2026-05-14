#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['9'] = '6';
        mp['8'] = '8';
        N = n;

        return rec(n);
    }

    // string str;
    unordered_map<char, char> mp;
    vector<string> ans;
    int N;

    vector<string> rec(int n) {
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};

        auto prev = rec(n - 2);
        vector<string> ans;
        for (auto p : prev) {
            for (auto m : mp) {
                if (m.first != '0' || n != N) ans.push_back(m.first + p + m.second);
            }
        }

        return ans;
    }
};
