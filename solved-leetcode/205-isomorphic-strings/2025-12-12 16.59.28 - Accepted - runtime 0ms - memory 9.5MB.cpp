class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> ms, mt;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (ms.find(c1) == ms.end() && mt.find(c2) == mt.end()) {
                ms[c1] = c2;
                mt[c2] = c1;
            } else if (ms[c1] != c2 || mt[c2] != c1)
                return false;
        }

        return true;
    }
};