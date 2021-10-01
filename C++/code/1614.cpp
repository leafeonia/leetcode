class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int balance = 0;
        for (char ch: s) {
            if (ch == '(') {
                balance++;
                ans = max(ans, balance);
            } else if (ch == ')') {
                balance--;
            }
        }
        return ans;
    }
};