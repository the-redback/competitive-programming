class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++) {
            mp[wordList[i]] = i;
        }
        if (mp.find(endWord) == mp.end()) return 0;

        map<string, int> visited, other;
        queue<pair<string, int>> q, oq;

        q.push({beginWord, 1});
        oq.push({endWord, 1});

        visited[beginWord] = 1;
        other[endWord] = 1;

        int ans = 10000007;
        while (!q.empty() && !oq.empty()) {
            if (q.size() > oq.size())
                ans = min(ans, visitNode(oq, other, visited));
            else
                ans = min(ans, visitNode(q, visited, other));
            // if(ans!=-1)
            //     return ans;
        }
        if (ans == 10000007) return 0;
        return ans;
    }

private:
    map<string, int> mp;

    int visitNode(queue<pair<string, int>>& q, map<string, int>& visited, map<string, int>& other) {
        auto tp = q.front();
        q.pop();
        int ans = 10000007;
        for (int i = 0; i < tp.first.size(); i++) {
            string str = tp.first;
            for (int k = 'a'; k <= 'z'; k++) {
                str[i] = k;
                if (mp.find(str) == mp.end() || visited.find(str) != visited.end()) continue;
                if (other.find(str) != other.end()) ans = min(ans, tp.second + other[str]);
                visited[str] = tp.second + 1;
                q.push({str, tp.second + 1});
            }
        }
        return ans;
    }
};

// Fast I/O; 4 ms.
static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
