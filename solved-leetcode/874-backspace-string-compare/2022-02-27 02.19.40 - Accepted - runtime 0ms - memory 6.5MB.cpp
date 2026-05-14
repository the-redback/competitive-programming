#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sq, tq;
        for (auto ch : s) {
            if (ch == '#' && !sq.empty()) sq.pop();
            if (ch != '#') sq.push(ch);
        }
        for (auto ch : t) {
            if (ch == '#' && !tq.empty()) tq.pop();
            if (ch != '#') tq.push(ch);
        }

        while (!sq.empty() && !tq.empty()) {
            if (sq.top() != tq.top()) return false;
            sq.pop();
            tq.pop();
        }

        return sq.empty() && tq.empty();
    }
};