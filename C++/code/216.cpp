class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    
    void backtrack(int left, int start, int k) {
        if (left == 0 && cur.size() == k) {
            ans.push_back(cur);
            return;
        } else if (left < 0 || cur.size() == k) return;
        for (int i = start;i < 10;i++) {
            cur.push_back(i);
            backtrack(left - i, i + 1, k);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n, 1, k);
        return ans;
    }
};