class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;

        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string u = q.front().first;
            int len = q.front().second;
            q.pop();

            for (int i = 0; i < u.size(); i++) {
                string str = u;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    str[i] = ch;

                    if (st.find(str) == st.end()) continue;

                    if (str == endWord) {
                        return len + 1;
                    }
                    st.erase(str);
                    q.push({str, len + 1});
                }
            }
        }

        return 0;
    }
};