class Solution {
    vector<vector<int>> dp;
public:
    int numTrees(int n) {
        if(n == 0) return 0;
//        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        dp.resize(n+1);
        for(int i = 0;i < n + 1;i++) dp[i].resize(n+1);
        for(int i = 0;i < n;i++) dp[i][i] = 1;
        for(int length = 1; length < n;length++){
            for(int i = 0;i + length < n;i++){
                int start = i;
                int fin = i + length;
                for(int j = start;j <= fin;j++){
                    dp[start][fin] += max(1,dp[start][j-1]) * max(1,dp[j+1][fin]);
                }
            }
        }
        return dp[0][n-1];
    }
};