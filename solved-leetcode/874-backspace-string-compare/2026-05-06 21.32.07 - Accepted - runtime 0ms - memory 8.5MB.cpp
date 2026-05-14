class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        while (i >= 0 || j >= 0) {
            int counter = 0;
            while (i >= 0 && (s[i] == '#' || counter)) {
                if (s[i] == '#')
                    counter++;
                else
                    counter--;
                i--;
            }

            counter = 0;
            while (j >= 0 && (t[j] == '#' || counter)) {
                if (t[j] == '#')
                    counter++;
                else
                    counter--;
                j--;
            }

            if (i < 0 || j < 0) return i < 0 && j < 0;

            if (s[i] != t[j]) return false;
            i--;
            j--;
        }

        return i < 0 && j < 0;
    }
};