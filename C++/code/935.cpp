class Solution {
public:
    int knightDialer(int n) {
        vector<int> dp(10, 1);
        int MOD = 1e9 + 7;
        for (int i = 0; i < n - 1; i ++) {
            vector<int> temp(10);
            temp[0] = (dp[4] + dp[6]) % MOD;
            temp[1] = (dp[8] + dp[6]) % MOD;
            temp[2] = (dp[7] + dp[9]) % MOD;
            temp[3] = (dp[8] + dp[4]) % MOD;
            temp[4] = ((dp[3] + dp[9]) % MOD + dp[0]) % MOD; //
            temp[6] = ((dp[1] + dp[7]) % MOD + dp[0]) % MOD; //
            temp[7] = (dp[2] + dp[6]) % MOD;
            temp[8] = (dp[1] + dp[3]) % MOD;
            temp[9] = (dp[4] + dp[2]) % MOD;
            dp = temp;
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};