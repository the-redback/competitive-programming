#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        pair<int, int> pr = {val, INT_MAX};
        if (!st.empty()) pr = st.top();
        pr.first = val;
        if (pr.second > val) pr.second = val;
        st.push(pr);
    }

    void pop() { st.pop(); }

    int top() {
        pair<int, int> pr = st.top();
        return pr.first;
    }

    int getMin() {
        pair<int, int> pr = st.top();
        return pr.second;
    }

private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */