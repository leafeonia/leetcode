class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> s;
        for (char ch: str) {
            if (ch == '(') s.push(0);
            else {
                int num = s.top() ? 2 * s.top() : 1;
                if (num != 1) s.pop();
                s.pop();
                while (!s.empty() && s.top()) {
                    num += s.top();
                    s.pop();
                }
                s.push(num);
            }
        }
        int ans = 0;
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};