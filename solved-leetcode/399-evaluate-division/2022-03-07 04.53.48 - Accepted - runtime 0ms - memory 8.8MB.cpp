#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        map<string, int> mp;
        vector<vector<double>> v(44, vector<double>(44, 0.0));

        for (int i = 0; i < equations.size(); i++) {
            auto eq = equations[i];
            if (mp.find(eq[0]) == mp.end()) mp[eq[0]] = mp.size();
            if (mp.find(eq[1]) == mp.end()) mp[eq[1]] = mp.size();

            int f = mp[eq[0]];
            int s = mp[eq[1]];

            v[f][f] = 1.0;
            v[s][s] = 1.0;
            v[f][s] = values[i];
            v[s][f] = 1.0 / values[i];
        }

        for (int k = 0; k < mp.size(); k++) {
            for (int i = 0; i < mp.size(); i++) {
                for (int j = 0; j < mp.size(); j++) {
                    if (v[i][j] == 0) v[i][j] = v[i][k] * v[k][j];
                }
            }
        }

        vector<double> ans;

        for (auto val : queries) {
            if (mp.find(val[0]) == mp.end() || mp.find(val[1]) == mp.end() || v[mp[val[0]]][mp[val[1]]] == 0)
                ans.push_back(-1);
            else
                ans.push_back(v[mp[val[0]]][mp[val[1]]]);
        }
        return ans;
    }
};