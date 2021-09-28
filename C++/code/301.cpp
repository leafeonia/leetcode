class Solution {
public:
    set<string> se;
    string cur;
    
    void dfs(int idx, int removedLeft, int removedRight, int balance) {
        if (idx == s.length()) {
            if (balance == 0 && removedLeft == left && removedRight == right) se.insert(cur);
            return;
        }    
        if (s[idx] == '(') {
            cur += "(";
            dfs(idx + 1, removedLeft, removedRight, balance + 1);
            cur.pop_back();
            if (removedLeft < left) {
                dfs(idx + 1, removedLeft + 1, removedRight, balance);
            }
        } else if (s[idx] == ')') {
            if (balance > 0) {
                cur += ")";
                dfs(idx + 1, removedLeft, removedRight, balance - 1);
                cur.pop_back();
            }
            if (removedRight < right) {
                dfs(idx + 1, removedLeft, removedRight + 1, balance);
            }
        }
        else {
            cur += s[idx];
            dfs(idx + 1, removedLeft, removedRight, balance);
            cur.pop_back();
        }
    }
    
    vector<string> removeInvalidParentheses(string ss) {
        s = ss;
        left = right = 0;
        for (char ch: s) {
            if (ch == '(') left++;
            else if (ch == ')') {
                if (left == 0) right++;
                else left--;
            }
        } 
        
        dfs(0, 0, 0, 0);
        vector<string> ans;
        for (string val: se) ans.push_back(val);
        return ans;
    }
    
    int left, right;
    string s;
};