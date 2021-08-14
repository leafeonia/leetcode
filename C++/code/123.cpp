class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        vector<vector<int>> dp(4, vector<int> (n, INT_MIN));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], -prices[i]);
        }
        for (int i = 1; i < 4; i++) {
            for (int j = i; j < n; j++) {
                int sign = i % 2 == 1 ? 1 : -1;
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + sign * prices[j]);
            }
        }
        if (n < 4) return max(0, dp[1][n - 1]);
        return max(0, max(dp[3][n - 1], dp[1][n - 1]));
    }
};

//                 3  3  5  0  0  3  1  4
//0 (no operation) 0  0  0  0  0  0  0  0
//1 (buy once)     -3 -3 -3 0  0  0  0  0
//2 (sell once)    0  0  2  2  2  3  3  4
//3 (buy twice)    0  0  -5 2  2  2  2  2 
//4 (sell twice)   0  0  0  -5 2  5  5  6