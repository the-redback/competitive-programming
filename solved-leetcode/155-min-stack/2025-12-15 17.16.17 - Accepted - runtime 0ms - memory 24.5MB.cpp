#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (mn.empty() || mn.top().first > val)
            mn.push({val, 1});
        else if (mn.top().first == val)
            mn.top().second++;
    }

    void pop() {
        if (mn.top().first == st.top()) mn.top().second--;
        if (mn.top().second == 0) mn.pop();
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return mn.top().first; }

private:
    stack<int> st;
    stack<pair<int, int> > mn;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */