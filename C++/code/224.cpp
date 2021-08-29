class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        st.push(1);
        int sign = 1;
        int ans = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = st.top();
                i++;
            } else if (s[i] == '-') {
                sign = -st.top();
                i++;
            } else if (s[i] == '(') {
                st.push(sign);
                i++;
            } else if (s[i] == ')') {
                st.pop();
                i++;
            } else {
                int num = s[i] - '0';
                i++;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                ans += sign * num;
            }
        }
        return ans;
    }
};
