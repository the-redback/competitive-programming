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

        unordered_map<char, int> mpattern;
        unordered_map<string, int> mwords;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (mpattern.find(c) == mpattern.end() && mwords.find(w) == mwords.end()) {
                mpattern[c] = i + 1;
                mwords[w] = i + 1;
            } else if (mpattern[c] != mwords[w])
                return false;
        }

        return true;
    }
};
