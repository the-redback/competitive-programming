#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int id = 0;
        for (int start = 0; start < n; start++) {
            if (s[start] == ' ') continue;
            if (id != 0) s[id++] = ' ';

            int end = start;
            while (end < n && s[end] != ' ') s[id++] = s[end++];

            reverse(s.begin() + id - (end - start), s.begin() + id);
            start = end;
        }

        s.erase(s.begin() + id, s.end());
        return s;
    }
};