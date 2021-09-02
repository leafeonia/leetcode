class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        stack<string> st;
        int idx = 0;
        while (idx < s.length()) {
            char ch = s[idx];
            if (ch == ' ') {
                idx++;
            } else if (isdigit(ch)) {
                string number;
                number += ch;
                while (idx < s.length() - 1 && isdigit(s[idx + 1])) {
                    number += s[idx + 1];
                    idx++;
                }
                int num = stoi(number);
                if (!st.empty()) {
                    if (st.top() == "*") {
                        st.pop();
                        int multiplier = stoi(st.top());
                        st.pop();
                        num *= multiplier;
                    } else if (st.top() == "/"){
                        st.pop();
                        int dividend = stoi(st.top());
                        st.pop();
                        num = dividend / num;
                    } else if (st.top() == "-") {
                        st.pop();
                        num = -num;
                    } else {
                        st.pop();
                    }
                }
                st.push(to_string(num));
                idx++;
            } else {
                string s(1, ch);
                st.push(s);
                idx++;
            } 
        }
        while (!st.empty()) {
            ans += stoi(st.top());
            st.pop();
        }
        return ans;
    }
};