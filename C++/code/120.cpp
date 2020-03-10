class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int n = triangle.size();
        vector<int> dp(n+1);
        for(int i = n - 1;i >= 0;i--){
            for(int j = 0;j <= i;j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};