class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += expand(s, i, i);
            result += expand(s, i, i + 1);
        }
        return result;
    }

    int expand(string& s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--, right++;
            count++;
        }
        return count;
    }
};