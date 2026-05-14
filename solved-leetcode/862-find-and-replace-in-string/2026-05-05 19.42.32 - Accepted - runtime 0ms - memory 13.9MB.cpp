class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> v;
        for (int i = 0; i < indices.size(); i++) {
            v.push_back({indices[i], i});
        }
        sort(v.begin(), v.end());

        string ans = "";
        int k = 0;
        for (int i = 0; i < v.size() && k < s.size(); i++) {
            while (k < s.size() && k != v[i].first) {
                ans += s[k];
                k++;
            }

            int u = v[i].second;

            if (k + sources[u].size() > s.size()) continue;

            if (s.substr(k, sources[u].size()) == sources[u]) {
                ans += targets[u];
                k += sources[u].size();
            }
        }

        while (k < s.size()) {
            ans += s[k];
            k++;
        }

        return ans;
    }
};