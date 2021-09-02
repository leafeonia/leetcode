class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        stack<int> st;
        int n = s.length();
        int curNum = 0;
        char op = '+';
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                curNum = curNum * 10 - '0' + ch;
            } 
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || i == n - 1){
                if (op == '+') st.push(curNum);
                else if (op == '-') st.push(-curNum);
                else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(curNum * top);
                } else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / curNum);
                }
                op = ch;
                curNum = 0;
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};