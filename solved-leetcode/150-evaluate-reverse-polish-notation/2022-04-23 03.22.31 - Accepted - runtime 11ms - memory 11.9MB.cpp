class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& ch : tokens) {
            if (ch == "+" || ch == "-" || ch == "/" || ch == "*") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if (ch == "+")
                    st.push(num1 + num2);
                else if (ch == "-")
                    st.push(num1 - num2);
                else if (ch == "/")
                    st.push(num1 / num2);
                else if (ch == "*")
                    st.push(num1 * num2);

            } else {
                st.push(stoi(ch));
            }
        }

        return st.top();
    }
};