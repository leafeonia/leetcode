class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};

// 0: have stock   1: do not have stock and not in cooldown   2: cooldown
//  0  1  2
//1 -1 0  0
//2 -1 0  1
//3 -1 1  2
//0 1  2  -1
//2 1  2  4