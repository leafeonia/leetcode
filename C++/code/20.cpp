class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0;i < s.length();i++){
            switch(s[i]){
                case '(':
                    st.push(1);
                    break;
                case '[':
                    st.push(2);
                    break;
                case '{':
                    st.push(3);
                    break;
                case ')':
                    if(st.empty() || st.top() != 1) return false;
                    st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top() != 2) return false;
                    st.pop();
                    break;
                case '}':
                    if(st.empty() || st.top() != 3) return false;
                    st.pop();
                    break;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};