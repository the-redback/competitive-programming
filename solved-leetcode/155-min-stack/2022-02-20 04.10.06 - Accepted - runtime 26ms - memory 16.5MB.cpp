#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (!mn.empty())
            mn.push(min(mn.top(), val));
        else
            mn.push(val);
    }

    void pop() {
        st.pop();
        mn.pop();
    }

    int top() { return st.top(); }

    int getMin() { return mn.top(); }

private:
    stack<int> st;
    stack<int> mn;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */