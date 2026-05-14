class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";

        int l = 0, r = 0;
        int mx = 0, in = 0;

        for (int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);

            if (len > mx) {
                mx = len;
                in = i;
            }
        }
        return s.substr(in - (mx - 1) / 2, mx);
    }

private:
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) left--, right++;
        return (right - left - 1);
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
