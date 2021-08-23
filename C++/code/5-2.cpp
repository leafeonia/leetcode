class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int rec = 1;
        int start = 0, end = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                start = i;
                end = i + 1;
            } else dp[i][i + 1] = 0;
            dp[i][i] = 1;
        }
        dp[n - 1][n - 1] = 1;
        for (int i = n - 3; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    if (j - i + 1 > rec) {
                        rec = j - i + 1;
                        start = i;
                        end = j;
                    }
                } else dp[i][j] = 0;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

//   0 1 2 3 4
// 0 1 0 1
// 1   1 0
// 2     1 0
// 3       1 0
// 4         1