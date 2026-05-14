#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftbalance = 0;
        for (auto ch : s) {
            if (ch == '(' || ch == '*')
                leftbalance++;
            else
                leftbalance--;

            if (leftbalance < 0) return false;
        }

        int rightbalance = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];
            if (ch == ')' || ch == '*')
                rightbalance++;
            else
                rightbalance--;

            if (rightbalance < 0) return false;
        }
        return true;
    }
};