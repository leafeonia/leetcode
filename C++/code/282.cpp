class Solution {
public:
    vector<string> ans;
    string num;
    int target;
    
    void dfs(int pos, string path, long long val, long long mult) {
        if (pos == num.length()) {
            if (val == target) {
                ans.push_back(path);
            }
            return;
        }    
        for (int i = pos; i < num.length(); i++) {
            if (num[pos] == '0' && pos != i) break;
            string cur = num.substr(pos, i - pos + 1);
            long long curNum = stol(cur);
            if (pos == 0) {
                dfs(i + 1, cur, curNum, curNum);
            } else {
                dfs(i + 1, path + "+" + cur, val + curNum, curNum);
                dfs(i + 1, path + "-" + cur, val - curNum, -curNum);
                dfs(i + 1, path + "*" + cur, val - mult + mult * curNum, mult * curNum);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        dfs(0, "", 0, 0);
        return ans;
    }
};