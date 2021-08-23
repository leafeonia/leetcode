class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                int num = triangle[i][j];
                if (j == i) dp[j] = dp[j - 1] + num;
                else if (j == 0) dp[j] = dp[j] + num;
                else dp[j] = min(dp[j], dp[j - 1]) + num;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) ans = min(ans, dp[i]);
        return ans;
    }
};