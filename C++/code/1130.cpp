class Solution {
public:
    int dfs(int left, int right, vector<vector<int>>& dp, vector<int>& arr, vector<vector<int>>& maxVal) {
        if (left == right) return 0;
        if (dp[left][right] != INT_MAX) return dp[left][right];
        int ret = INT_MAX;
        for (int i = left; i < right; i++) {
            ret = min(ret, dfs(left, i, dp, arr, maxVal) + dfs(i + 1, right, dp, arr, maxVal) + maxVal[left][i] * maxVal[i + 1][right]);
        }
        dp[left][right] = ret;
        return ret;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> maxVal(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int record = 0;
            for (int j = i; j < n; j++) {
                record = max(record, arr[j]);
                maxVal[i][j] = record;
            }
        }
        dfs(0, n - 1, dp, arr, maxVal);
        return dp[0][n - 1];
    }
};
