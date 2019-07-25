class Solution {
public:
    long long dp[102][102];
    long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(!m) return 0;
        int n = obstacleGrid[0].size();
        memset(dp,0, sizeof(dp));
        dp[1][1] = 1 - obstacleGrid[0][0];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(i == 1 && j == 1) continue;
                if(obstacleGrid[i-1][j-1] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};