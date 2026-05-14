class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> mpattern;
        unordered_map<string, char> mwords;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (mpattern.find(c) == mpattern.end() && mwords.find(w) == mwords.end()) {
                mpattern[c] = w;
                mwords[w] = c;
            } else if (mpattern[c] != w || mwords[w] != c)
                return false;
        }

        return true;
    }
};
