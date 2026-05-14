#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        rev(s, 0, n - 1);
        int id = 0;

        for (int start = 0; start < n; start++) {
            if (s[start] == ' ') continue;
            if (id != 0) s[id++] = ' ';

            int end = start;
            while (end < n && s[end] != ' ') s[id++] = s[end++];

            rev(s, id - (end - start), id - 1);
            start = end;
        }

        s.erase(s.begin() + id, s.end());
        return s;
    }

    void rev(string& s, int i, int j) {
        while (i < j) {
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
            i++, j--;
        }
        return;
    }
};