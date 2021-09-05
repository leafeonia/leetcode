class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<string>> dp(n + 1, vector<string>());
        for (int i = 1; i <= n; i++) {
            for (string word: wordDict) {
                int le = word.length();
                if (i >= le && s.substr(i - le, le) == word) {
                    if (i == le) dp[i].push_back(word);
                    else {
                        for (string prevWord: dp[i - le]) {
                            dp[i].push_back(prevWord + " " + word);
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};

// pineapplepenapple
