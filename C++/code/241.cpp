class Solution {
public:
    vector<int> nums;
    vector<char> ops;
    int n;
    
    vector<int> dfs(int left, int right) {
        if (left == right) {
            vector<int> v{nums[left]};
            return v;
        }
        vector<int> ret;
        for (int i = left; i < right; i++) {
            vector<int> leftResult = dfs(left, i);
            vector<int> rightResult = dfs(i + 1, right);
            for (int l: leftResult) {
                for (int r: rightResult) {
                    switch (ops[i]) {
                        case '+' :
                            ret.push_back(l + r);
                            break;
                        case '-' :
                            ret.push_back(l - r);
                            break;
                        case '*' :
                            ret.push_back(l * r);
                            break;
                    }
                }
            }
        }
        return ret;
    }
    
    vector<int> diffWaysToCompute(string exp) {
        int opIdx = -1;
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
                nums.push_back(stoi(exp.substr(opIdx + 1, i - opIdx - 1)));
                ops.push_back(exp[i]);
                opIdx = i;
            }
        }
        nums.push_back(stoi(exp.substr(opIdx + 1)));
        n = nums.size();
        vector<int> ans = dfs(0, n-1);
        return ans;
    }
};