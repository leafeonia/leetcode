class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string str: tokens) {
            if (isdigit(str.back())) {
                st.push(stoi(str));
                continue;
            }
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (str == "+") st.push(a + b);
            else if (str == "-") st.push(b - a);
            else if (str == "*") st.push(a * b);
            else if (str == "/") st.push(b / a);
        }
        return st.top();
    }
};