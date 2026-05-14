#include <string>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int result = 0;
        int i = 0, n = s.size();

        while (i < n && s[i] == ' ') i++;

        if (i < n && s[i] == '+') {
            sign = 1;
            i++;
        } else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                if (sign == 1) return INT_MAX;
                return INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};
