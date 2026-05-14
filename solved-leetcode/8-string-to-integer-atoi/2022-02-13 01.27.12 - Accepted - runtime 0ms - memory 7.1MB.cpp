#include <string>
using namespace std;

enum State { q0, q1, q2, qd };

class Solution {
    State currentState;
    int result, sign;

    void toStateQ1(char& ch) {
        if (ch == '-')
            sign = -1;
        else
            sign = 1;
        currentState = q1;
    }

    void toStateQ2(char& ch) {
        currentState = q2;
        appendDigit(ch);
    }

    void toStateQd() { currentState = qd; }

    void appendDigit(char& ch) {
        int digit = ch - '0';
        if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            if (sign == 1)
                result = INT_MAX;
            else {
                result = INT_MIN;
                sign = 1;
            }
            toStateQd();
        } else {
            result = result * 10 + digit;
        }
    }

    void transition(char& ch) {
        if (currentState == q0) {
            if (ch == ' ')
                return;
            else if (ch == '-' || ch == '+')
                toStateQ1(ch);
            else if (isdigit(ch))
                toStateQ2(ch);
            else
                toStateQd();
        } else if (currentState == q1 || currentState == q2) {
            if (isdigit(ch))
                toStateQ2(ch);
            else
                toStateQd();
        }
    }

public:
    int myAtoi(string s) {
        currentState = q0;
        result = 0;
        sign = 1;

        for (int i = 0; i < s.size() && currentState != qd; i++) {
            transition(s[i]);
        }

        return sign * result;
    }
};