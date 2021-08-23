class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> temp(m, vector<int>(n, 0));
        vector<vector<int>> dires{{1,0},{0,1},{-1,0},{0,-1}};
        
        const int MOD = 1e9 + 7;
        dp[startRow][startColumn] = 1;
        ans[startRow][startColumn] = 1;
        
        for (int l = 0; l < maxMove - 1; l++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (auto& dire: dires) {
                        int x = i + dire[0];
                        int y = j + dire[1];
                        if (x < 0 || x >= m || y < 0 || y >= n) continue;
                        temp[x][y] = (temp[x][y] + dp[i][j]) % MOD;
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    ans[i][j] = (ans[i][j] + temp[i][j]) % MOD;
                    dp[i][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < m; i++) answer = (answer + ans[i][0]) % MOD;
        for (int i = 0; i < m; i++) answer = (answer + ans[i][n - 1]) % MOD;
        for (int i = 0; i < n; i++) answer = (answer + ans[0][i]) % MOD;
        for (int i = 0; i < n; i++) answer = (answer + ans[m - 1][i]) % MOD;
        return answer;
    }
};