class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        vector<vector<double>> temp(n, vector<double>(n, 0));
        vector<vector<int>> dires{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        dp[row][column] = 1.0;
        for (int l = 0; l < k; l++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] > 0) {
                        for (auto& dire: dires) {
                            int x = i + dire[0];
                            int y = j + dire[1];
                            if (x < 0 || x >= n || y < 0 || y >= n) continue;
                            temp[x][y] += dp[i][j] * 0.125;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};