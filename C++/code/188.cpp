class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m = prices.size();
        if (m < 2) return 0;
        int n = 2 * min(k, m / 2) + 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) dp[0][i] = -prices[0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int sign = j % 2 == 1 ? -1 : 1;
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + sign * prices[i]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

//    0  1  2  3  4 ... 2*k
// 3  0  -3 0 -3  0
// 2  0  -2 0 -2  0
// 6  0  -2 4 -2  4
// 5  0  -2 4 -1  4
// 0  0  0  4  4  4
// 3  0  0  4  4  7