class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= n; i++) {
            for (string word: wordDict) {
                if (i >= word.length() && s.substr(i - word.length(), word.length()) == word) dp[i] |= dp[i - word.length()];
            }
        }
        return dp[n];
    }
};