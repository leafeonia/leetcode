class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] <= k;
    }
    
    // abcdeca
    //   0 1 2 3 4 5 6 
    // 0 0 1 2 3 4 3 2
    // 1   0 1 2 3 2 3
    // 2     0 1 2 1 2
    // 3       0 1 2 3
    // 4         0 1 2
    // 5           0 1
    // 6             0
};