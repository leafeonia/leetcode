class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string num;
        for (char ch: s) {
            if (isalpha(ch)) {
                string s2(1, ch);
                if (st.empty() || !isalpha(st.top()[0])) st.push(s2);
                else st.top() += ch;
            }
            else if (isdigit(ch)) {
                num += ch;
            } else if (ch == '[') {
                st.push(num);
                num = "";
            } else if (ch == ']') {
                string s2 = st.top();
                st.pop();
                int number = stoi(st.top());
                st.pop();
                string s3;
                for (int i = 0; i < number; i++) s3 += s2;
                if (!st.empty() && isalpha(st.top()[0])) {
                    s3 = st.top() + s3;
                    st.pop();
                }
                st.push(s3);
            }
        }
        return st.top();
    }
};