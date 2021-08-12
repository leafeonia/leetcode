class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) dp[i] = i;
        for (int i = 1; i <= m; i++) {
            int upleft = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                int val;
                if (word1[i - 1] == word2[j - 1]) val = upleft;
                else val = min(dp[j - 1], min(dp[j], upleft)) + 1;
                upleft = dp[j];
                dp[j] = val;
            }
        }
        return dp[n];
    }
};