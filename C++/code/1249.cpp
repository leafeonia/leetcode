class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans, ans2;
        int cnt = 0;
        for (char ch: s) {
            if (ch == ')') {
                if (cnt == 0) continue;
                cnt--;
            } else if (ch == '(') {
                cnt++;
            } 
            ans += ch;
        }
        for (int i = ans.length() - 1; i >= 0; i--) {
            if (ans[i] == '(' && cnt) {
                cnt--;
                continue;
            }
            ans2 += ans[i];
        }
        reverse(ans2.begin(), ans2.end());
        return ans2;
    }
};