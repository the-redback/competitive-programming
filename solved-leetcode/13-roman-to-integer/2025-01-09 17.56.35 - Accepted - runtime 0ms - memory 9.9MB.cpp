#include <string>

using namespace std;


class Solution {
public:
    int convertToInt(char ch) {
        if (ch == 'I')
            return 1;
        else if (ch == 'V')
            return 5;
        else if (ch == 'X')
            return 10;
        else if (ch == 'L')
            return 50;
        else if (ch == 'C')
            return 100;
        else if (ch == 'D')
            return 500;
        else if (ch == 'M')
            return 1000;

        return 0;
    }

    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int curr = convertToInt(s[i]);

            if (i + 1 < n) {
                int nxtNumber = convertToInt(s[i + 1]);

                if (curr < nxtNumber) {
                    curr = nxtNumber - curr;
                    i++;
                }
            }
            ans += curr;
        }

        return ans;
    }
};