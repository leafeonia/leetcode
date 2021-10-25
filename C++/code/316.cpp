class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int> visited(26, 0);
        vector<int> lastPos(26, -1);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            lastPos[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[s[i] - 'a']) {
                while (!ans.empty() && ans.back() > s[i] && lastPos[ans.back() - 'a'] > i) {
                    visited[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                visited[s[i] - 'a'] = 1;
            }
        }
        return ans;
    }
};