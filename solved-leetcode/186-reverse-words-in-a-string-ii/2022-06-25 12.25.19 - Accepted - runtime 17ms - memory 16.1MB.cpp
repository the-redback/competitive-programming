class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int start = 0;
        for (int start = 0; start < n; start++) {
            if (s[start] == ' ') start++;

            int end = start;
            while (end < n && s[end] != ' ') {
                end++;
            }

            reverse(s.begin() + start, s.begin() + end);
            start = end;
        }
        return;
    }
};