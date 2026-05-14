class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int si = s.size() - 1, ti = t.size() - 1;
        while (si >= 0 || ti >= 0) {
            int ci = 0;
            while (si >= 0 && (s[si] == '#' || ci > 0)) {
                if (s[si] == '#')
                    ci++;
                else
                    ci--;
                si--;
            }

            int ct = 0;
            while (ti >= 0 && (t[ti] == '#' || ct > 0)) {
                if (t[ti] == '#')
                    ct++;
                else
                    ct--;
                ti--;
            }

            if (si < 0 || ti < 0) return si < 0 && ti < 0;

            if (s[si] != t[ti]) return false;
            si--;
            ti--;
        }
        return si < 0 && ti < 0;
    }
};