class Solution {
public:
    string decodeString(string s) {
        i = 0;
        return rec(s);
    }

    int i;  // i needs to be shared to track index globally.

    string rec(string& s) {
        string str;

        while (i < s.size() && s[i] != ']') {
            if (isalpha(s[i])) {
                str += s[i];
                i++;
            } else if (isdigit(s[i])) {
                int k = 0;

                while (i < s.size() && isdigit(s[i])) {
                    k = k * 10 + s[i] - '0';
                    i++;
                }

                i++;  // skip '['
                string decodedString = rec(s);

                i++;  // ignore the closing bracket ']'
                while (k--) {
                    str += decodedString;
                }
            }
            cout << i << " ";
        }
        return str;
    }
};