class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = s.size() - 1;

        while (last >= 0 && s[last] == ' ') last--;

        int i = last;
        while (i >= 0 && s[i] != ' ') i--;

        return last - i;
    }
};