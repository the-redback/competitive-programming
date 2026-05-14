class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> mp;
        map<char, vector<char>> graph;

        for (auto word : words) {
            for (auto ch : word) {
                graph[ch] = {};
                mp[ch] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            if (s1.size() > s2.size() && s2 == s1.substr(0, s2.size())) return "";

            for (int j = 0; j < min(s1.size(), s2.size()); j++) {
                if (s1[j] != s2[j]) {
                    graph[s1[j]].push_back(s2[j]);
                    mp[s2[j]]++;
                    break;
                }
            }
        }

        queue<char> q;
        for (auto ch : mp) {
            // cout<<ch.first<<" "<<ch.second<<endl;
            if (ch.second == 0) q.push(ch.first);
        }

        string ans = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            ans += c;

            for (auto ch : graph[c]) {
                mp[ch]--;
                if (mp[ch] == 0) {
                    q.push(ch);
                }
            }
        }

        if (mp.size() != ans.size()) return "";

        return ans;
    }
};