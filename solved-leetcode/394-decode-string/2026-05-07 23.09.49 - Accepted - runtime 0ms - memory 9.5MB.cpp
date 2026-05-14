#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (auto ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + ch - '0';
            } else if (isalpha(ch)) {
                currentString += ch;
            } else if (ch == '[') {
                numStack.push(k);
                stringStack.push(currentString);
                k = 0;
                currentString = "";
            } else if (ch == ']') {
                int count = numStack.top();
                string decodedString = stringStack.top();
                numStack.pop();
                stringStack.pop();

                while (count--) {
                    decodedString += currentString;
                }

                currentString = decodedString;
            }
        }

        return currentString;
    }
};