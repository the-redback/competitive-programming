#include <map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        val.resize(44, 1.0);
        par.resize(44);
        for (int i = 0; i < par.size(); i++) {
            par[i] = i;
        }

        for (int i = 0; i < equations.size(); i++) {
            auto eq = equations[i];
            if (mp.find(eq[0]) == mp.end()) mp[eq[0]] = mp.size();
            if (mp.find(eq[1]) == mp.end()) mp[eq[1]] = mp.size();

            int f = mp[eq[0]];
            int s = mp[eq[1]];

            // val[f]=values[i];
            Union(f, s, values[i]);
        }
        vector<double> ans;

        for (auto v : queries) {
            if (mp.find(v[0]) == mp.end() || mp.find(v[1]) == mp.end()) {
                ans.push_back(-1);
                continue;
            }

            int f = mp[v[0]];
            int s = mp[v[1]];

            int fpar = find(f);
            int spar = find(s);
            if (fpar != spar) {
                ans.push_back(-1);
                continue;
            }

            ans.push_back(val[f] / val[s]);
        }

        return ans;
    }

private:
    map<string, int> mp;
    vector<double> val;
    vector<int> par;

    int find(int node) {
        if (par[node] == node) {
            return node;
        }

        int p = find(par[node]);
        if (par[node] != p) {
            val[node] *= val[par[node]];
            par[node] = p;
        }
        return par[node];
    }

    void Union(int divident, int divisor, double value) {
        int dividentPar = find(divident);
        int divisorPar = find(divisor);

        if (par[dividentPar] != divisorPar) {
            par[dividentPar] = divisorPar;
            val[dividentPar] = val[divisor] * value / val[divident];
        }
        return;
    }
};