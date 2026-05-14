#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> cs;
        stack<string> ss;
        string str = "";
        int k = 0;

        for (auto ch : s) {
            if (isdigit(ch))
                k = k * 10 + ch - '0';
            else if (isalpha(ch)) {
                str += ch;
            } else if (ch == '[') {
                cs.push(k);
                k = 0;
                ss.push(str);
                str = "";
            } else if (ch == ']') {
                string dec = "";
                // ss.pop();
                int cnt = cs.top();
                cs.pop();
                for (int i = 0; i < cnt; i++) dec += str;
                dec = ss.top() + dec;
                str = dec;
                ss.pop();
            }
        }
        return str;
    }
};